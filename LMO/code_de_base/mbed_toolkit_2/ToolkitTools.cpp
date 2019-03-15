#include "ToolkitTools.h"

DigitalOut *myled;
Serial *serial;

void initToolkitTools(){
    myled = new DigitalOut(LED1);
    serial = new Serial(USBTX, USBRX);
}

void testSerial(){
    *myled = 1;
    wait(1);
    *myled = 0;
    wait(0.2);
    serial->printf("I blink !\n");
}