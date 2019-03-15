#include <stdlib.h>
#include <stdio.h>

float ck(float* x,float*  y,int k,int  n){
	if(k==0){return y[n];}
	float res = 0;
	for(int j = 0; j <= k; j++){
		float temp = y[n-j];
		for(int i = 0; i<=k;i++){
			if(i != j){temp *= 1/(x[n-j]-x[n-i]);}
		}
		res += temp;
	}
	return res;
}

void cupdate(float* x,float* y,float* c,int n){
	c = calloc(n+1,sizeof(*c));
	for(int k=0;k<=n;k++){
		c[n-k]=ck(x,y,k,n);
	}
}

float newton(float* x, float* y, float* c, int n){
	cupdate(x,y,c,n);
	int res = c[n];
	for(int i = 1; i<=n;i++){
		temp = c[n-i];
		for(int j = 0; j < i ; j++){
			temp *= (x[n-i]-x[n-j]);
		}
		res += temp;
	}
	return res;
}

int main(){
	int n = 4;
	float* c;
	printf("tets");
	float* x = calloc(n+1,sizeof(*x));
	float* y = calloc(n+1,sizeof(*y));
		x[4] = 0.0;
		x[3] = 1.1;
		x[2] = 2.3;
		x[1] = 4.3;
		x[0] = 5.1;
	for(int i = 0;i<=n;i++){
		y[n-i] = 20;
	} 
	printf("test");
	cupdate(x,y,c,n);
	for(int k = 0;k<=n;k++){
		printf("c%d = %f",k,c[n-k]);
	}
}
