# Correction
* Remettre tout à niveau

## Pseudo-code

correction(unit16 data[128]){

	float K_bruit-blanc = 200;
	double = fc;
	int seuil =  5 ;
	unit16 data_traite[128- 2 seuil];
	for(int i = seuil, i<128-seuil; ++i){
	fc = 6,27e-6 i^4 - 0,01434 i^3 + 0,151 i^2 -5,794 i + 24,94;
	data_trate[i] = data[i] K / fc;
	}
	return data_traite, taille(data_traite);
}

# Trajectoire

# Régulation
regulation(vitess, delta_l, delta_r){
	
	delta = moyenne(delta_l, delta_r);

	var= (delta_prece/delta) K;

	vit_new = vitesse var;
}

