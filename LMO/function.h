


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


uint16 detect(y[n], data_trait[?]){
	int rech_seuil = 15, i;
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


void detection(x[n], data_trait[?], (adr)l[n], (adr)r[n]){
	xupdate(x[n], vel, fps);
	if(detect(l[n], data_trait[?]) >= 0 ) put(detect(l[n], data_trait[?]), l[n]);
	else put(newton(x[n], l[n]), l[n]);

	if(detect(r[n], data_trait[?]) >= 0 ) put(detect(r[n], data_trait[?]), r[n]);
	else put(newton(x[n], r[n]), r[n]);
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

regulation_vitesse(vmax, vmin, e[0]){
	v = vmax - ((vmax-vmin)/b) e[0];
}

void val_erreur(uint16 l, uint16 r, uint16 b, float * e){
	float err = abs(((l-r)/2)-b);
	put(err, *e);
}




