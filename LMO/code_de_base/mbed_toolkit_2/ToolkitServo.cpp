#include "ToolkitServo.h"
#include "ToolkitTools.h"

float servoDirection = 0.0;

PwmOut servo(PTA12);

void initToolkitServo(){
    float p0 = (SERVO_MAX_PULSE_WIDTH + SERVO_MIN_PULSE_WIDTH)/2.0;//centered position
    servo.period(SERVO_PERIOD);
    servo.pulsewidth(p0);
}

void setServoPWM(float dir){
    //security
    dir=(dir>1.0)?1.0:dir;
    dir=(dir<-1.0)?-1.0:dir;
    
    servoDirection = dir;
    
    float t = dir*(SERVO_MAX_PULSE_WIDTH-SERVO_MIN_PULSE_WIDTH)/2+(SERVO_MAX_PULSE_WIDTH+SERVO_MIN_PULSE_WIDTH)/2.0;
    servo.pulsewidth(t);
    
}

void setServoPWMDebug(float periodMin, float periodMax){
    
    float t = (periodMax-periodMin)/2+(periodMax+periodMin)/2.0;
    servo.pulsewidth(t);
}

//to calibrate the servo sweep pulsewidths from 0.0003 to 0.0025 seconds. find the extreme values and then find the middle pulsewidth.
void calibrateServo(){
    
    float time = 0.0003;
    *myled = !*myled;
    wait(1);
    while ( time < SERVO_PERIOD ){   
       
        servo.pulsewidth(time);
        *myled = !*myled;
        wait(1);
        if (serial->getc())
            serial->printf("%f\n",time);
        
        time = time + 0.00001;
    }
    serial->printf("Error\n");

}

void testServo(float maxDir){//sweep
    setServoPWM(0.0);
    *myled = 1;
    wait(3);
    *myled = 0;
    
    setServoPWM(-maxDir);
    wait(0.5);
    setServoPWM(maxDir);
    wait(0.5);
}
