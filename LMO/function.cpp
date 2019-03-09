#include "function.h"

float * put(void* val, void* *table, int size){ //checked
	float buf;
	for(i = 1; i<size; ++i){
		buf = table[i-1];
		table[i] = buf;
	}
	table[0] = val;
	return table;
}

void xupdate(float *x, int sizexy, float vel, float fps){ //checked
	float x_suiv = fps*vel+x[0];
	x = put(x_suiv, x, sizexy);
}

float * ck(float *x, float *y, int n){ //to check une deuxieme fois
	float c[n+1], temp;
	for(k=1; k<=n; ++k){
		c[k] = 0;
		for(j = 0; j<=k; ++j){
			temp = y[j];
			for(i=0; i<=k && i!=j; ++i){
				temp = temp/(x[j]-x[i]);
			}
			c[k]+=temp;
		}
	}
	return c;
}

void newton(float *x, float *y, int n){ //to check une deuxieme fois
	N = y[0];
	float * c[n+1] = ck(x, y, n), temp;
	for(int i = 1; i <= n; ++i){
		temp = c[i]; 
		for(int j =0; j<i; ++j){
			temp*=(x[0] - x[j]);
		}
		N+=temp;
	}
	put(N, y, n+1);
}

void detection(float *x, int sizexy, double *data_trait, int sizedat, uint16 *l, uint16 *r, int sizelr){ //to check
	xupdate(x, sizexy, vel, fps);
	if(detect(l, data_trait) >= 0 ) l = put(detect(l, data_trait), l, sizelr);
	else l = put(newton(x, l), l);

	if(detect(r, data_trait) >= 0 ) r = put(detect(r, data_trait), r, sizelr);
	else r = put(newton(x, r), r, sizelr);
}

int detect(float * y, int sizexy, double * data_trait){ //checked type data trait, retour int
	int rech_seuil = 15, i;
	if(y[0]<rech_seuil){
		for(i=0; i<y[0]+rech_seuil+1; ++i){
			if(data_trait[y[0]+i] < detect_seuil) break;
		}
	}
	else if (y[0]>sizexy - rech_seuil){
		for(i=y[0]-rech_seuil; i<sizexy; ++i){
			if(data_trait[y[0]+i] < detect_seuil) break;
		}
	}
	else{
		for(i=-rech_seuil; i<rech_seuil+1; ++i){
			if(data_trait[y[0]+i] < detect_seuil) break;
		}
	}
	if(i<rech_seuil+1){
		put(y[0]+i, y, sizexy);
		return y[0]+i;
	}
	else{
		put(-1, y, sizexy);
		return -1;
	}
}

uint16 correction(uint16 data[128], double *data_trait, int *sizedat){
	float K_bruit-blanc = 200;
	double = fc, coefffc[5]= {24.94, 5.794, 0.151, 0.01434, 6.27e-6} //les facteurs seront à déterminer par nous meme
	int seuil =  5 , *sizedat = 128-2*seuil;
	double data_traite[*sizedat];
	uint16 b = (127/2) - seuil;
	for(int i = seuil, i<128-seuil; ++i){
	double fc = coefffc[4]*i*i*i*i - coefffc[3]*i*i*i + coefffc[2]*i*i -coefffc[1]*i + coefffc[0]; 
	data_trate[i] = data[i]*K_bruit-blanc / fc;
	
	}
	return b; //data_traite, taille(data_traite), 
}

void val_erreur(uint16 *l, uint16 *r, int sizelr, uint16 b,  double *e, int sizee){ //to check
	double err = abs(((l-r)/2)-b);
	put(err, e, sizee);
}

float regulation_vitesse(float vmax, float vmin, double e){ //to check
	float v = vmax - ((vmax-vmin)/b) e; //ici e = e[0]
}

float trajectoire(double *e, int sizee){ //to check
	float t = 0;
	t+=Kp e[0];
	t+= Kd(e[0]-e[1]);
	for(i = 0; i<sizee; ++i) t+= e[i]*Ki;
	return t;
}

