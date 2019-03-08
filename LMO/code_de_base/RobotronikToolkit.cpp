#include "RobotronikToolkit.h"

DigitalOut myled(LED1);
Serial pc(USBTX, USBRX);

//Right motor
PwmOut rightMotorForward(PTC8);
PwmOut rightMotorBackward(PTC9);
//Left motor
PwmOut leftMotorForward(PTA5);
PwmOut leftMotorBackward(PTA4);
//The signals sent to the DC are forward-backward for each

//Servo
PwmOut servo(PTA12);

//Scan line camera
//PwmOut cameraClock(PTB9);//Use PwmOut: causes crash: a custom clock must be implemented
DigitalOut cameraClock(PTB9);
DigitalOut cameraStart(PTB8); //trigger the aquisition
AnalogIn cameraData(PTC2);//to retrieve each of the 128 pixels

char scanLine[128]; //store the last scan result

void initToolkit(){
    
    //------------------------------Motor and Servo------------------------------
    float p0 = (SERVO_MAX_PULSE_WIDTH + SERVO_MIN_PULSE_WIDTH)/2.0;//centered position
    
    //init PWM periods
    rightMotorForward.period(MOTOR_PERIOD);
    rightMotorBackward.period(MOTOR_PERIOD);
    leftMotorForward.period(MOTOR_PERIOD);
    leftMotorBackward.period(MOTOR_PERIOD);
    servo.period(SERVO_PERIOD);
    
    //set to 0
    rightMotorForward.write(0.5);
    rightMotorBackward.write(0.5);
    leftMotorForward.write(0.5);
    leftMotorBackward.write(0.5);
    
    //servo.write(0.5);
    servo.pulsewidth(p0);
    
    //------------------------------Scan line camera------------------------------
    //init the thread handling the camera clock chanel
}


void updateToolkit(){//pour debug
    //must process the instructions sent through the serial port from the computer
}

// -1< motorL/R <+1
void setMotorPWM(float motorL, float motorR){
    //security check
    //*/
    motorL=(motorL>1.0)?1.0:motorL;
    motorL=(motorL<-1.0)?-1.0:motorL;
    motorR=(motorR>1.0)?1.0:motorR;
    motorR=(motorR<-1.0)?-1.0:motorR;
    //*/
    
    rightMotorForward.write(0.5+motorR/2);
    rightMotorBackward.write(0.5-motorR/2);
    
    leftMotorForward.write(0.5001+motorL/2);
    leftMotorBackward.write(0.5001-motorL/2);
    
}

//dir btw [-1,+1], 0:straight, -:left, +:right
void setServomotorPWM(float dir){
    //security
    dir=(dir>1.0)?1.0:dir;
    dir=(dir<-1.0)?-1.0:dir;
    
    float t = dir*(SERVO_MAX_PULSE_WIDTH-SERVO_MIN_PULSE_WIDTH)/2+(SERVO_MAX_PULSE_WIDTH+SERVO_MIN_PULSE_WIDTH)/2.0;
    servo.pulsewidth(t);
}

void readCamera(int data[]){
    
    //send the starting SI signal
    cameraStart.write(1);
    wait(CAMERA_SI_PERIOD);
    cameraStart.write(0);
    
    //retrieve each of the 128 pixel as analog values
    for(int i=0; i<128; i++){
        cameraClock.write(1);
        data[i] = (int)(cameraData.read()*128);
        wait(CAMERA_CLK_PERIOD/2);
        cameraClock.write(0);
        wait(CAMERA_CLK_PERIOD/2);
    }
    cameraClock.write(1);
    wait(CAMERA_CLK_PERIOD);
    cameraClock.write(0);
    
    //send the closing SI signal
    cameraStart.write(1);
    wait(CAMERA_SI_PERIOD);
    cameraStart.write(0);
}

void readCamera2(int data[]){
    int i=0;
    int j=0;
    do{
        cameraClock.write(1);
        if(j>0){
            data[j] = (int)(cameraData.read()*42);
        }
        wait(CAMERA_CLK_PERIOD/2);
        cameraClock.write(0);
        wait(CAMERA_CLK_PERIOD/2);
        
        if(i==25){
            cameraStart.write(1);
            wait(CAMERA_SI_PERIOD);
            cameraStart.write(0);
        }
        
        if(j==129){
            cameraStart.write(1);
            wait(CAMERA_SI_PERIOD);
            cameraStart.write(0);
        }
        
        i++;
        if(i>25)
            j++;
        
    }while(j<200);
    
}

void detect(int img[], int &left, int &right){
    
}

//---------------------------------------------Tests and calibration---------------------------------------------
void testServo(float maxDir){
    setServomotorPWM(0.0);
    myled = 1;
    wait(3);
    myled = 0;
    
    setServomotorPWM(-maxDir);
    wait(0.5);
    setServomotorPWM(maxDir);
    wait(0.5);
}

void calibrateServo(){
    
}

void testMotorDC(float max){
    myled=1;
    setMotorPWM(0.001, 0.0);
    wait(1);
    myled=0;
    setMotorPWM(max, max);
    wait(1);
}

void testCamera(){
    int data[128];
    //retrive data from the camera
    readCamera2(data);
    
    //send data to camera
    pc.printf("----------Camera----------\n");
    for(int i=0; i<128; i++)
        pc.printf("%d ", data[i]);
    pc.printf("\n");
    wait(1);
}

void calibrateCamera(){
    
}

void testSerial(){
    myled = 1;
    wait(1);
    myled = 0;
    wait(0.2);
    pc.printf("I blink !\n");
}
