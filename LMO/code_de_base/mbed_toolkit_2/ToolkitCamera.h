#include "mbed.h"

#define CAMERA_PERIOD (float)(0.0001)//sec 0.001
#define CAMERA_VAR_MAX 100

/* Pin number related: 
    PTB8   (Camera CCD1 SI)\n
    PTB9   (Camera CCD1 CLK)\n
    PTC2   (Camera CCD1 A0)\n
*/

void initToolkitCamera();
void readCameraTickDemi();

void testCamera();
