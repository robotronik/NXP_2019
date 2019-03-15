#include "mbed.h"

extern DigitalOut* myled;
extern Serial* serial;

/* Pin number:
    PTA12  Servo 1\n
    PTA13  Servo 2\n
    
    PTB8   (Camera CCD1 SI)\n
    PTB9   (Camera CCD1 CLK)\n
    PTC2   (Camera CCD1 A0)\n

    PTA4    Motor1 PWM1 FTM0_CH1\n
    PTA5    Motor1 PWM2 FTM0_CH2\n
    PTC8    Motor2 PWM1 FTM0_CH4\n
    PTC9    Motor2 PWM2 FTM0_CH5\n
*/

void initToolkitTools();
void testSerial();


