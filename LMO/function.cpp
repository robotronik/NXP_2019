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

float * ck(float *x, float *y, int sizexy){ //to check
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

void newton(float *x, float *y, int sizexy){ //to check
	N = y[0];
	float * c[sizexy] = ck(x, y, sizexy), temp;
	for(int i = 1; i <= sizexy; ++i){
		temp = c[i]; 
		for(int j =0; j<i; ++j){
			temp*=(x[0] - x[j]);
		}
		N+=temp;
	}
	put(N, y, sizexy);
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

correction(unit16 data[128]){
	float K_bruit-blanc = 200;
	double = fc;
	int seuil =  5 ;
	unit16 data_traite[128- 2 seuil];
	uint16 b = (127/2) - seuil;
	for(int i = seuil, i<128-seuil; ++i){
	fc = 6,27e-6*i^4 - 0,01434*i^3 + 0,151*i^2 -5,794*i + 24,94; //les facteurs seront à déterminer par nous meme
	data_trate[i] = data[i]*K_bruit-blanc / fc;
	
	}
	return data_traite, taille(data_traite), b;
}

void val_erreur(unit16 *l, unit16 *r, int sizelr, uint16 b,  unit16 *e, int sizee){ //to check
	uint16 err = abs(((l-r)/2)-b);
	put(err, e, sizee);
}

float regulation_vitesse(float vmax, float vmin, unit16 e){ //to check
	float v = vmax - ((vmax-vmin)/b) e; //ici e = e[0]
}

trajectoire(e[m]){
	t = 0;
	t+=Kp e[0];
	t+= Kd(e[0]-e[1]);
	for(i = 0; i<m; ++i) t+= e[i]*Ki;
	return t;
}

