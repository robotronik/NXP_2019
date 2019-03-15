#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <cstdint>

#define vmax (float) 100 
#define vmin (float) 1

float regulation_vitesse(float v_max, float v_min, float e, uint8_t b){//checked retour ajoute
	float v ;
	if(e<0.8) v = (vmax-vmin)*exp(-1.83*abs(e))+vmin;
	else v = vmin;
	if(v>1) return 1;
	return v/(vmax-vmin);
}


int main(){
	float e = 0.2;
	uint8_t b = 64;
	printf("%f\n", regulation_vitesse(vmax, vmin, e, b));

}
