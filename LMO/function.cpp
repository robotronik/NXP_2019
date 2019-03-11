#include "function.h"

float * put(void* val, void* *table, uint8_t size){ //checked
	float buf;
	for(uint8_t i = 1; i<size; ++i){
		buf = table[i-1];
		table[i] = buf;
	}
	table[0] = val;
	return table;
}

void xupdate(float *x, uint8_t sizexy, float vel, float fps){ //checked
	float x_suiv = fps*vel+x[0];
	x = put(x_suiv, x, sizexy);
}

float * ck(float *x, int16_t *y, uint8_t n){ //checked
	float c[n+1], temp;
	for(uint8_t k=1; k<=n; ++k){
		c[k] = 0;
		for(uint8_t j = 0; j<=k; ++j){
			temp = y[j];
			for(uint8_t i=0; i<=k && i!=j; ++i){
				temp = temp/(x[j]-x[i]);
			}
			c[k]+=temp;
		}
	}
	return c;
}

void newton(float *x, int16_t *y, uint8_t n){ //checked
	int16_t N = y[0];
	float c[n+1] = ck(x, y, n), temp;
	for(uint8_t i = 1; i <= n; ++i){
		temp = c[i]; 
		for(uint8_t j =0; j<i; ++j){
			temp*=(x[0] - x[j]);
		}
		N+=temp;
	}
	if(N<-128) N=-128;
	else if(N>255) N=255;
	put(N, y, n+1);
}

void detection(float *x, uint8_t sizexy, float *data_trait, uint8_t sizedat, int16_t *l, int16_t *r, uint8_t sizelr){ //checked
	xupdate(x, sizexy, vel, fps);
	uint8_t left = detect(l, data_trait);
	if(left <= 128  && left > 0) l = put(detect(l, data_trait), l, sizelr);
	else l = put(newton(x, l), l, sizelr);

	uint8_t right = detect(r, data_trait);
	if(right <= 128  && right > 0) r = put(detect(r, data_trait), r, sizelr);
	else r = put(newton(x, r), r, sizelr);
}

uint8_t detect(int16_t * y, uint8_t sizexy, float * data_trait, uint8_t sizedat){ //checked type data trait, retour int
	uint8_t rech_seuil = 15, i;
	// if(y[0]<rech_seuil){
	// 	for(i=0; i<y[0]+rech_seuil+1; ++i){
	// 		if(data_trait[y[0]+i] < detect_seuil) break;
	// 	}
	// }
	// else if (y[0]>sizexy - rech_seuil){
	// 	for(i=y[0]-rech_seuil; i<sizexy; ++i){
	// 		if(data_trait[y[0]+i] < detect_seuil) break;
	// 	}
	// }
	// else{
	// 	for(i=-rech_seuil; i<rech_seuil+1; ++i){
	// 		if(data_trait[y[0]+i] < detect_seuil) break;
	// 	}
	//}
	// switch (y[0]) {
	// 	case y[0]<-rech_seuil :
	// 	return 250;
	// 	case y[0]<rech_seuil:
	// 	for(i=0; i<rech_seuil+y[0]+1; ++i){
	// 		if(data_trait[i]<detect_seuil){
	// 			put(i, y, sizexy);
	// 			return i;
	// 		}
	// 	}
	// 	case y[0]<sizedat-rech_seuil-1:
	// 	for(i=y[0]-rech_seuil; i<rech_seuil+y[0]+1; ++i){
	// 		if(data_trait[i]<detect_seuil){
	// 			put(i, y, sizexy);
	// 			return i;
	// 		}
	// 	}

	// 	case y[0]>sizedat-rech_seuil-1:
	// 	for(i=y[0]-rech_seuil; i<sizedat-1; ++i){
	// 		if(data_trait[sizedat-1-i]<detect_seuil){
	// 			put(sizedat-1-i, y, sizexy);
	// 			return sizedat-1-i;
	// 		}
	// 	}

	// 	case y[0]>rech_seuil+sizedat-1:
	// 	return 250;

	// }
	if(y[0]<-rech_seuil) return 250;
	else if(y[0]<rech_seuil){
		for(i=0; i<rech_seuil+y[0]+1; ++i){
			if(data_trait[i]<detect_seuil){
				put(i, y, sizexy);
				return i;
			}
		}
	}
	else if(y[0]<sizedat-rech_seuil-1){
		for(i=y[0]-rech_seuil; i<rech_seuil+y[0]+1; ++i){
			if(data_trait[i]<detect_seuil){
				put(i, y, sizexy);
				return i;
			}
		}
	}
	else if(y[0]>sizedat-rech_seuil-1){
		for(i=y[0]-rech_seuil; i<sizedat-1; ++i){
			if(data_trait[sizedat-1-i]<detect_seuil){
				put(sizedat-1-i, y, sizexy);
				return sizedat-1-i;
			}
		}
	}
	else if(y[0]>rech_seuil+sizedat-1) return 250;
	else return 139;


	// if(i<rech_seuil+1){
	// 	put(y[0]+i, y, sizexy);
	// 	return y[0]+i;
	// }
	// else{
	// 	put(-1, y, sizexy);
	// 	return 250;
	// }
}

uint8_t correction(uint8_t data[128], float *data_trait, uint8_t *sizedat){//checked
	float K_bruit-blanc = 200;
	float = fc, coefffc[5]= {24.94, 5.794, 0.151, 0.01434, 6.27e-6} //les facteurs seront à déterminer par nous meme
	uint8_t seuil =  5 , *sizedat = 128-2*seuil;
	float data_trait[*sizedat];
	uint8_t b = (127/2) - seuil;
	for(uint8_t i = seuil, i<128-seuil; ++i){
		float fc = coefffc[4]*i*i*i*i - coefffc[3]*i*i*i + coefffc[2]*i*i -coefffc[1]*i + coefffc[0]; 
		data_trait[i] = data[i]*K_bruit-blanc / fc;
	}
	return b; //data_traite, taille(data_traite), 
}

void val_erreur(uint8_t *l, uint8_t *r, uint8_t sizelr, uint8_t b,  float *e, uint8_t sizee){ //checked
	float err = ((((l-r)/2)-b)<0) ? ((l-r)/2)-b:-(((l-r)/2)-b);
	put(err, e, sizee);
}

float regulation_vitesse(float vmax, float vmin, float e){ //checked retour ajoute
	float v = vmax - ((vmax-vmin)/b) * e; //ici e = e[0]
	return v;
}

float trajectoire(float *e, uint8_t sizee){ //checked
	float t = 0;
	t+= Kp*e[0];
	t+= Kd*(e[0]-e[1]);
	for(uint8_t i = 0; i<sizee; ++i) t+= e[i]*Ki;
		return t;
}

