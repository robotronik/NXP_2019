#include "mbed.h"
#include "ToolkitTools.h"
#include "ToolkitServo.h"
#include "ToolkitMotors.h"
#include "ToolkitCamera.h"
//#include "CarLink.h"

//CarLink carlink(USBTX, USBRX);

void init();
bool loop();

int main(){
    initToolkitTools();
    initToolkitServo();
    initToolkitMotors();
    initToolkitCamera();

    init();
    
    //loop
    while(loop()){
        //carlink.sendData();
    };
}

void init(){
    
}

bool loop(){
    testCamera();
    wait(0.1);
    return true;
}