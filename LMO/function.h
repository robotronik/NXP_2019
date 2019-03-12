#include <stdlib.h>
#include <stdio.h>
#include <cstdint>
#include <iostream>

#define FPS (float) 30.0
#define DETECT_SEUIL 200


void bidon(uint8_t* a);
void ajouteu8(uint8_t val, uint8_t *table, uint8_t size);
void ajouteu16(int16_t val, int16_t *table, uint8_t size);
void ajoutefl(float val, float *table, uint8_t size);
void xupdate(float *x, uint8_t sizexy, float vel, float fps);
float * ck(float *x, int16_t *y, uint8_t n);
void newton(float *x, int16_t *y, uint8_t n);
void detection(float *x, uint8_t sizexy, float *data_trait, uint8_t sizedat, int16_t *l, int16_t *r, uint8_t sizelr, float vel);
uint8_t detect(int16_t * y, uint8_t sizexy, float * data_trait, uint8_t sizedat);
uint8_t correction(uint8_t data[128], float *data_trait, uint8_t *sizedat);
void val_erreur(uint8_t *l, uint8_t *r, uint8_t sizelr, uint8_t b,  float *e, uint8_t sizee);
float regulation_vitesse(float vmax, float vmin, float e);
float trajectoire(float *e, uint8_t sizee);
