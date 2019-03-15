#include "mbed.h"
#include "ToolkitTFC.h"

void initToolkitTFC(){
    TFC_Init();
}
    
void testCameraTFC(){
    //int test = (TFC_LineScanImageReady == 1) ;
    //serial.printf("\d\n", test);
    
    if(TFC_LineScanImageReady == 1){
        serial->printf("----------Camera----------\n");
        for(int i=0; i<128; i++)
            serial->printf("%d ", TFC_LineScanImage0[i]);
        serial->printf("\n");
        TFC_LineScanImageReady = 0;
    }
}

