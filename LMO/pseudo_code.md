# Correction
* Remettre tout à niveau

## Pseudo-code

correction(unit16 data[128]){

	float K_bruit-blanc = 200;
	double = fc;
	int seuil =  5 ;
	unit16 data_traite[128- 2 seuil];
	for(int i = seuil, i<128-seuil; ++i){
	fc = 6,27e-6 i^4 - 0,01434 i^3 + 0,151 i^2 -5,794 i + 24,94; //les facteurs sront à déterminer par nous meme
	data_trate[i] = data[i] K / fc;
	//calculer b (mileu de la piste)
	}
	return data_traite, taille(data_traite);
}

# Trajectoire

val_erreur(l[n], r[n], b, e[n]){
	
	e = abs(((l-r)/2)-b);
	e.put(e);
	return e (par adr)

}

trajectoire(e[n]){
	
	t = 0;
	t+=Kp e[0];
	t+= Kd(e[0]-e[1]);
	for(i = 0; i<n; ++i) t+= e[i] Ki;
	return t;
 
}

# Régulation
regulation(vmax, vmin, e[0]){
	
	v = vmax - ((vmax-vmin)/b) e[0];


}

# DDL

9 : {K, seuil, fc}, {vmax, vmin}, !!!!! {Kp, Ki, Kd}, n !!!!!

