#include "mbed.h"

#define MOTOR_PERIOD (float)(0.020) //sec

/* Pin number related:
    PTA4    Motor1 PWM1 FTM0_CH1\n
    PTA5    Motor1 PWM2 FTM0_CH2\n
    PTC8    Motor2 PWM1 FTM0_CH4\n
    PTC9    Motor2 PWM2 FTM0_CH5\n
*/

void initToolkitMotors();

void setMotorPWM(float motorL, float motorR);

void testMotorDC(float max);
void calibrateServo();
