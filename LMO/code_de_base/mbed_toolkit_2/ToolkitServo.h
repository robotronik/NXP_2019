#pragma once

#include "mbed.h"

#define SERVO_PERIOD (float)(0.020) //sec
#define SERVO_MIN_PULSE_WIDTH (float)0.00100  //sec, min=right limit
#define SERVO_MAX_PULSE_WIDTH (float)0.00145  //sec, max=left limit

/* Pin number related:
    PTA12  Servo 1\n
    PTA13  Servo 2\n
*/

void initToolkitServo();

void setServoPWM(float dir);// between -+1
void setServoPWMDebug(float periodMin, float periodMax);
void testServo(float maxDir);//sweep