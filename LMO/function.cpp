#include "function.h"

float * put(uint16 val, uint16 *table, uint16 size_of_table){
	for(i = 1; i<size_of_table; ++i){
		buf = table[i-1];
		table[i] = buf;
	}
	table[0] = val;
	return table;
}

void xupdate(uint16 *x, uint16 size_of_x, uint16 vel, uint16 fps){
	uint16 x_suiv = fps*vel+x[0];
	put(x_suiv, x, size_of_x);
}

uint16 detect(uint16 *y, uint16 *data_trait, uint16 size_of_y, uint16 size_of_data_trait){
	int rech_seuil = 15, i;
	if(y[0]<rech_seuil){
		for(i=0; i<y[0]+rech_seuil+1; ++i){
			if(data_trait[y[0]+i] < detect_seuil) break;
		}
	}
	else if (y[0]>size_of_y - rech_seuil){
		for(i=y[0]-rech_seuil; i<size_of_y; ++i){
			if(data_trait[y[0]+i] < detect_seuil) break;
		}
	}
	else{
		for(i=-resc_seuil; i<rech_seuil+1; ++i){
			if(data_trait[y[0]+i] < detect_seuil) break;
		}
	}
	if(i<rech_seuil+1) put(i, y, size_of_y);
	else put(-1, y, size_of_y);
}

void detection(uint16 *x, uint16 size_of_x, uint16 *data_trait, uint16 size_of_data_trait, uint16 *l, uint16 size_of_l, uint16 *r, uint16 size_of_r){
	xupdate(x, size_of_x, vel, fps);
	if(detect(l, data_trait, size_of_l, size_of_data_trait) >= 0 ) put(detect(l, data_trait, size_of_l, size_of_data_trait), l[n]);
	else put(newton(x[n], l[n]), l[n]);

	if(detect(r[n], data_trait[?]) >= 0 ) put(detect(r[n], data_trait[?]), r[n]);
	else put(newton(x, r, size_of_r), r, size_of_r);
}


float * ck(uint16 *x, uint16 *y, uint16 size){
	float c[size], temp;
	for(k=1; k<=size; ++k){
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

void newton(uint16 *x, uint16 *y, uint16 size){
	unint16 N = y[0];
	float * c[size] = ck(x, y, size), temp;
	for(int i = 1; i <= size; ++i){
		temp = c[i]; 
		for(int j =0; j<i; ++j){
			temp*=(x[0] - x[j]);
		}
		N+=temp;
	}
	put(N, y, size);
}