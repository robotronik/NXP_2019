#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <cstdint>
#include <iostream>

#define FPS (float) 30.0
#define DETECT_SEUIL 200
#define K_BRUIT 200
#define RECH_SEUIL 20
#define SIZE_DATA 118//to do if SEUIL change 128-2*SEUIL
#define SEUIL 5
#define B 59 //Milieu de data_trait
#define VMAX 100
#define VMIN (float) 0.1
#define KP 1
#define KD 0
#define KI 0
#define SIZE_LR 5
#define SIZE_X 5
#define SIZE_E 3

void ajouteu8(uint8_t val, uint8_t *table, uint8_t size);
void ajouteu16(int16_t val, int16_t *table, uint8_t size);
void ajoutefl(float val, float *table, uint8_t size);
void update(float *x,int16_t* y, uint8_t n, float vel);
float ck(float* x, int16_t*  y,int k,uint8_t  n);
float * cupdate(float* x,int16_t* y,uint8_t n);
float newton(float* x, int16_t* y, float xsuiv, uint8_t n);
void detection(float *x, float *data_trait, int16_t *l, int16_t *r, float vel);
int16_t detect(int16_t * y, float * data_trait);
void correction(uint8_t data[128], float *data_trait);
void val_erreur(int16_t *l, int16_t *r, float *e);
float regulation_vitesse(float e0);
float trajectoire(float *e);
void conduire(uint8_t data[128], float* data_trait, float* x, int16_t* l, int16_t* r, float* e, float* vel, float* traj);
