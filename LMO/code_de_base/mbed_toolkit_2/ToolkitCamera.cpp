#include "ToolkitCamera.h"
#include "ToolkitTools.h"
#include <stdlib.h>

unsigned int scanLinePixels[128];//store the last scan result
unsigned int scanLinePixelsBuffer[128];//used as buffer during the acquisition
Ticker tick;
int bitIndex = -2;

//PwmOut cameraClock(PTB9);//Use PwmOut: causes crash: a custom clock must be implemented
DigitalOut cameraClock(PTB9);
DigitalOut cameraStart(PTB8); //trigger the aquisition
AnalogIn cameraData(PTC2);//to retrieve each of the 128 pixels

void initToolkitCamera(){
    
    tick.attach(&readCameraTickDemi, CAMERA_PERIOD/2);
}

void readCameraTickDemi(){
    
    switch(bitIndex){
        case -2:{//start the acquisition
            cameraStart.write(0);
            break;
        }
        case -1:{
            cameraStart.write(1);
            break;
        }
        case 0:{//first bit part 1
            cameraClock.write(1);
            break;
        }
        case 1:{//first bit part 2
            scanLinePixelsBuffer[0] = (unsigned int)(cameraData.read()*CAMERA_VAR_MAX);
            cameraStart.write(0);
            cameraClock.write(0);
            break;
        }
        case 256:{//127*2=254, so bitIndex=256 is the first part of a supplementary period1 (255 is the second part of the bit at i=127)
            cameraClock.write(1);
            break;
        }
        case 257:{//second part of the supplementary period1 and end of the acquisition
            cameraClock.write(0);
            for(int i=0; i<128; i++)
                scanLinePixels[i] = scanLinePixelsBuffer[i];
                
            bitIndex =-2;
            return;
        }
        default:{//classic bit
            
            if(bitIndex%2){//if a sub period
                scanLinePixelsBuffer[bitIndex/2] = (unsigned int)(cameraData.read()*CAMERA_VAR_MAX);
                cameraClock.write(0);
            } else
                cameraClock.write(1);
                
            break;
        }
    }
    bitIndex++;
}

void testCamera(){
    serial->printf("----------Camera----------\n");
    for(int i=0; i<128; i++)
        serial->printf("%d ", scanLinePixels[i]);
    serial->printf("\n");
    wait(0.01);
}
