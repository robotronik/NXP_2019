#include "ToolkitMotors.h"
#include "ToolkitTools.h"

float speedL = 0.0;
float speedR = 0.0;

//Right motor
PwmOut rightMotorForward(PTC8);
PwmOut rightMotorBackward(PTC9);
//Left motor
PwmOut leftMotorForward(PTA5);
PwmOut leftMotorBackward(PTA4);
//The signals sent to the DC are forward-backward for each

void initToolkitMotors(){
    //init PWM periods
    rightMotorForward.period(MOTOR_PERIOD);
    rightMotorBackward.period(MOTOR_PERIOD);
    leftMotorForward.period(MOTOR_PERIOD);
    leftMotorBackward.period(MOTOR_PERIOD);
    
    //set to 0
    rightMotorForward.write(0.5);
    rightMotorBackward.write(0.5);
    leftMotorForward.write(0.5);
    leftMotorBackward.write(0.5);
}

void setMotorPWM(float motorL, float motorR){
    //security check
    motorL=(motorL>1.0)?1.0:motorL;
    motorL=(motorL<-1.0)?-1.0:motorL;
    motorR=(motorR>1.0)?1.0:motorR;
    motorR=(motorR<-1.0)?-1.0:motorR;
    
    rightMotorForward.write(0.5+motorR/2);
    rightMotorBackward.write(0.5-motorR/2);
    
    leftMotorForward.write(0.5001+motorL/2);
    leftMotorBackward.write(0.5001-motorL/2);
    
    speedL = motorL;
    speedR = motorR;
    
}

void testMotorDC(float max){
    *myled=1;
    setMotorPWM(0.001, 0.0);
    wait(1);
    *myled=0;
    setMotorPWM(max, max);
    wait(1);
}
