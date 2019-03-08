#include "mbed.h"

#define MOTOR_PERIOD (float)(0.020) //sec

#define SERVO_PERIOD (float)(0.020) //sec
#define SERVO_MIN_PULSE_WIDTH (float)0.00100  //sec, min=right limit
#define SERVO_MAX_PULSE_WIDTH (float)0.00145  //sec, max=left limit

#define CAMERA_CLK_PERIOD (float)(0.0002)
#define CAMERA_SI_PERIOD (float)(0.0002) //for the SI signal

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
    }
*/

void initToolkit();
void updateToolkit();

void setMotorPWM(float motorL, float motorR);
void setServomotorPWM(float dir);
void readCamera(int data[]);
void readCamera2(int data[]);

//void detect(int img[], int &left, int &right);
void sendRealTimeLog();//send to the PC the data using CustomCarLink

//------------------------------Tests and calibration------------------------------
void testServo(float maxDir);//sweep
void calibrateServo();
void testMotorDC(float max);

void testCamera();
void calibrateCamera();

void testSerial();

