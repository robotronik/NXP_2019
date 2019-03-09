float * put(float val, float *table, int size);
void xupdate(float *x, int size, float vel, float fps);
float * ck(float *x, float *y, int sizexy);
void newton(float *x, float *y, int sizexy);
void detection(float *x, int sizexy, uint16 *data_trait, int sizedat, uint16 *l, uint16 *r, int sizelr):
void detect(float * y, int sizexy, uint16 data_trait);
// correction
void val_erreur(unit16 *l, unit16 *r, int sizelr, uint16 b,  unit16 *e, int sizee);
float regulation_vitesse(float vmax, float vmin, unit16 e);
float trajectoire(unit16 *e, int sizee);
