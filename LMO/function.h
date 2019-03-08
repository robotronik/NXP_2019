

regulation_vitesse(vmax, vmin, e[0]){
	v = vmax - ((vmax-vmin)/b) e[0];
}

void val_erreur(uint16 l, uint16 r, uint16 b, float * e){
	float err = abs(((l-r)/2)-b);
	put(err, *e);
}




