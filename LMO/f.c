#include "function.h"

void ajouteu8(uint8_t val, uint8_t *table, uint8_t size){ //funk
	for(uint8_t i = size-1; i>0; --i){
		table[i] = table[i-1];
	}
	table[0] = val;
}

void ajouteu16(int16_t val, int16_t *table, uint8_t size){ //funk
	for(uint8_t i = size-1; i>0; --i){
		table[i] = table[i-1];
	}
	table[0] = val;
}

void ajoutefl(float val, float *table, uint8_t size){ //funk
	for(uint8_t i = size-1; i>0; --i){
		table[i] = table[i-1];
	}
	table[0] = val;
}

void update(float *x,int16_t* y, uint8_t n, float vel, float fps){ //funk
	float xsuiv = fps*vel+x[0];
	int16_t ysuiv = newton(x,y,xsuiv,n);

	ajoutefl(xsuiv, x, n);
	ajouteu16(ysuiv, y, n);
}

float ck(float* x, int16_t*  y,int k,uint8_t  n){//funk
	if(k==0){return y[n];}
	float res = 0;
	for(uint8_t j = 0; j <= k; j++){
		float temp = y[n-j];
		for(uint8_t i = 0; i<=k;i++){
			if(i != j){temp *= 1./(x[n-j]-x[n-i]);}
		}
		// printf("%d %f\n",j, temp);
		res += temp;
	}
	return res;
}

float * cupdate(float* x,int16_t* y,uint8_t n){//funk
	float* c = (float*) calloc(n+1,sizeof(float));
	for(uint8_t k=0;k<=n;k++){
		c[n-k]=ck(x,y,k,n);
		// printf("BITE A DUDULE\n");
	}
	return c;
}

float newton(float* x, int16_t* y, float xsuiv, uint8_t n){//funky
	float* c = cupdate(x,y,c,n);
	float res = c[n];
	float temp;
	for(uint8_t i = 1; i<=n;i++){
		temp = c[n-i];
		// printf("c%d = %f\t",i, c[n-i]);
		for(uint8_t j = 0; j < i ; j++){
			temp *= (xsuiv-x[n-j]);
			// printf("%f\t", xsuiv-x[n-j]);
		}
		// printf("pour c%d le terme vaut: %f\n",i,temp);
		res += temp;
	}
	free(c);
	return res;
}

void detection(float *x, uint8_t sizexy, float *data_trait, int16_t *l, int16_t *r, uint8_t sizelr, float vel){ //checked
	int16_t left = detect(l, sizelr, data_trait);
	if(left <= 128  && left > 0){ 
		ajouteu16(left, l, sizelr);
		ajoutefl(FPS*vel+x[0], x, n);
	}
	else update(x, l, sizelr, vel, FPS);

	int16_t right = detect(r, sizelr, data_trait);
	if(right <= 128  && right > 0) { 
		ajouteu16(right, r, sizelr);
		ajoutefl(FPS*vel+x[0], x, n);
	}
	else update(x, r, sizelr, vel, FPS);
}

int16_t detect(int16_t * y, uint8_t sizexy, float * data_trait){ //checked type data trait, retour int
	uint8_t i;
	if(y[0]<-RECH_SEUIL) return 250;
	else if(y[0]<RECH_SEUIL){
		for(i=0; i<RECH_SEUIL+y[0]+1; ++i){
			if(data_trait[i]<DETECT_SEUIL){
				ajouteu16(i, y, sizexy);
				return i;
			}
		}
	}
	else if(y[0]<SIZE_DATA-RECH_SEUIL-1){
		for(i=y[0]-RECH_SEUIL; i<RECH_SEUIL+y[0]+1; ++i){
			if(data_trait[i]<DETECT_SEUIL){
				ajouteu16(i, y, sizexy);
				return i;
			}
		}
	}
	else if(y[0]>SIZE_DATA-RECH_SEUIL-1){
		for(i=y[0]-RECH_SEUIL; i<SIZE_DATA-1; ++i){
			if(data_trait[SIZE_DATA-1-i]<DETECT_SEUIL){
				ajouteu16(SIZE_DATA-1-i, y, sizexy);
				return SIZE_DATA-1-i;
			}
		}
	}
	else if(y[0]>RECH_SEUIL+SIZE_DATA-1) return 250;
	return 139;
}

void correction(uint8_t data[128], float *data_trait){//checked
	float fc, coefffc[5]= {24.94, 5.794, 0.151, 0.01434, 6.27e-6}; //les facteurs seront à déterminer par nous meme
	//defined by SIZE_DATA
	//*SIZE_DATA = 128-2*seuil;
	data_trait = (float*) calloc(SIZE_DATA, sizeof(*data_trait));
	//uint8_t b = (127/2) - seuil;
	for(uint8_t i = seuil; i<128-seuil; ++i){
		float fc = coefffc[4]*i*i*i*i - coefffc[3]*i*i*i + coefffc[2]*i*i -coefffc[1]*i + coefffc[0]; 
		data_trait[i] = data[i]*K_BRUIT / fc;
	} //data_traite, taille(data_traite), 
}

void val_erreur(uint8_t *l, uint8_t *r, uint8_t sizelr, uint8_t b,  float *e, uint8_t sizee){ //checked range err (-1, 1)
	float err = ((((l-r)/2)-b)<0) ? ((l-r)/2)-b:-(((l-r)/2)-b);
	ajoutefl(err/64., e, sizee);
}

float regulation_vitesse(float v_max, float v_min, float e, uint8_t b){//funk af
	if(e<0.8) v = (vmax-vmin)*exp(-1.83*abs(e))+vmin;
	else v = vmin;
	if(v>1) return 1;
	return v/(vmax-vmin);
}

float trajectoire(float *e, uint8_t sizee){ //checked
	float t = 0, Kp, Kd, Ki;
	t+= Kp*e[0]; 
	t+= Kd*(e[0]-e[1]);
	for(uint8_t i = 0; i<sizee; ++i){
		t+= e[i]*Ki;
	}
	return t;
}

//varibale dans le main vel,l,r,x,e,data_trait, traj
//define FPS, sizelr, detectseuil, rechseuil, vmax,vmin, sizee, SIZE_DATA, K_BRUIT, Coefffc
void conduire(uint8_t data[128], float* data_trait, float* x, int16_t* l, int16_t* r, float* e, float* vel, float* traj){ZE_DATA	//Update vel
	vel = regulation_vitesse(vmax, vmin, e, b);

	//Angle to b range(-1,1)
	traj = trajectoire(e,sizee);

	//Write to PWM
}