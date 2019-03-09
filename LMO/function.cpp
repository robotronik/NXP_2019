#include "function.h"

float * put(float val, float *table, int size){ //to check
	float buf;
	for(i = 1; i<size; ++i){
		buf = table[i-1];
		table[i] = buf;
	}
	table[0] = val;
	return table;
}

void xupdate(float *x, int sizexy, float vel, float fps){ //to check
	float x_suiv = fps*vel+x[0];
	x = put(x_suiv, x, sizexy);
}

float * ck(float x, float y, int sizexy){
	float c[sizexy], temp;
	for(k=1; k<=sizexy; ++k){
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

void newton(x[n], y[n]){
	N = y[n];
	c[n] = ck(x[n], y[n]);
	for(int i = 1; i <= n; ++i){
		temp = c[i]; 
		for(int j =0; j<i; ++j){
			temp*=(x[0] - x[j]);
		}
		N+=temp;
	}
	put(N, y[n]);
}

void detection(float *x, int sizexy, uint16 *data_trait, int sizedat, uint16 *l, uint16 *r, int sizelr){ //to check
	xupdate(x, sizexy, vel, fps);
	if(detect(l, data_trait) >= 0 ) l = put(detect(l, data_trait), l, sizelr);
	else l = put(newton(x, l), l);

	if(detect(r, data_trait) >= 0 ) r = put(detect(r, data_trait), r, sizelr);
	else r = put(newton(x, r), r, sizelr);
}

void detect(float * y, int sizexy, uint16 data_trait){ //to check
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
	if(i<rech_seuil+1) put(i, y, sizexy);
	else put(-1, y, sizexy);
}



