# Correction
* Remettre tout à niveau

## Pseudo-code

correction(unit16 data[128]){

	float K_bruit-blanc = 200;
	double = fc;
	int seuil =  5 ;
	unit16 data_traite[128- 2 seuil];
	uint16 b = (127/2) - seuil;
	for(int i = seuil, i<128-seuil; ++i){
	fc = 6,27e-6*i^4 - 0,01434*i^3 + 0,151*i^2 -5,794*i + 24,94; //les facteurs sront à déterminer par nous meme
	data_trate[i] = data[i]*K_bruit-blanc / fc;
	
	}
	return data_traite, taille(data_traite), b;
}

# Trajectoire

val_erreur(l[n], r[n], b, e[m]){
	
	err = abs(((l-r)/2)-b);
	put(err, e[n]);
	return e (par adr)

}

trajectoire(e[m]){
	
	t = 0;
	t+=Kp e[0];
	t+= Kd(e[0]-e[1]);
	for(i = 0; i<m; ++i) t+= e[i]*Ki;
	return t;
 
}

regulation_vitesse(vmax, vmin, e[0]){
	
	v = vmax - ((vmax-vmin)/b) e[0];


}

float * put(val, table[n]){
	
	for(i = 1; i<n; ++i){
		buf = table[i-1];
		table[i] = buf;
	}
	table[0] = val;
	return table;

}

void xupdate(x[n], vel, fps){
	
	x_suiv = fps*vel+x[0];
	put(x_suiv, x[n]);

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


float * ck(x[n], y[n]){
	
	float c[n];
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

void detection(x[n], data_trait[?], (adr)l[n], (adr)r[n]){
	
	xupdate(x[n], vel, fps);
	if(detect(l[n], data_trait[?]) >= 0 ) put(detect(l[n], data_trait[?]), l[n]);
	else put(newton(x[n], l[n]), l[n]);

	if(detect(r[n], data_trait[?]) >= 0 ) put(detect(r[n], data_trait[?]), r[n]);
	else put(newton(x[n], r[n]), r[n]);


}

uint16 detect(y[n], data_trait[?]){
	
	int rech_seuil = 15, i;
	if(y[0]<rech_seuil || y[0]>n - rech_seuil)
	if(y[0]<rech_seuil){
		for(i=0; i<y[0]+rech_seuil+1; ++i){
			if(data_trait[y[0]+i] < detect_seuil) break;
		}
	}
	else if (y[0]>n - rech_seuil){
		for(i=y[0]-rech_seuil; i<n; ++i){
			if(data_trait[y[0]+i] < detect_seuil) break;
		}
	}
	else{
		for(i=-resc_seuil; i<rech_seuil+1; ++i){
			if(data_trait[y[0]+i] < detect_seuil) break;
		}
	}
	if(i<rech_seuil+1) put(i,y[n]);
	else put(-1, y[n]);

}



# DDL

12 : {K_bruit-blanc, seuil, fc}, {vmax, vmin}, !!!!! {Kp, Ki, Kd}, n(degrès polynome), m(longueur intégration)!!!!! {rech_seuil, detect_seuil}

