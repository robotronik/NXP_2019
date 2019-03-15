#include "mbed.h"
#include "ToolkitTools.h"
#include "ToolkitServo.h"
#include "ToolkitMotors.h"
#include "ToolkitCamera.h"
#include "ToolkitDive.h"
//#include "CarLink.h"

extern unsigned int *scanLinePixels;

//CarLink carlink(USBTX, USBRX);

void init();
bool loop();

int main(){
    initToolkitTools();
    initToolkitServo();
    initToolkitMotors();
    initToolkitCamera();

    //definition for ToolkitDrive
    uint8_t data[128];
    int16_t *l, *r;
    float *data_trait, *x, *e, vel, traj;
    float v_max=0.2;



    init();
    
    //loop
    while(loop()){
        //carlink.sendData();
    };
}

void init(){
    x = (float*) calloc(SIZE_X, sizeof(float));
    e = (float*) calloc(SIZE_E, sizeof(float));
    e = {0};
    data_trait = (float*) calloc(SIZE_DATA, sizeof(*data_trait));
    l = (int16_t*) calloc(SIZE_LR, sizeof(int16_t));
    r = (int16_t*) calloc(SIZE_LR, sizeof(int16_t));
    l[0] = 0+RECH_SEUIL;
    r[0] = SIZE_DATA-RECH_SEUIL;
    vel = 0;
    for(uint8_t i = 0;i<=SIZE_LR;i++){
        data[128] = (uint8_t) scanLinePixels;
        correction(data[128],data_trait);
        detection(x,data_trait,l,r,vel);
    }
    vel = VMIN * v_max;
    traj = 0;
    setServoPWM(traj);
    setMotorPWM(vel,vel);
    return;
}

bool loop(){
    data[128] = (uint8_t) scanLinePixels;
    conduire(data[128],data_trait,x,l,r,e,&vel,&traj);
    vel *= v_max;
    setServoPWM(traj);
    setMotorPWM(vel,vel);
    return true;
}