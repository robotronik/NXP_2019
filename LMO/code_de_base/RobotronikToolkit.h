#include "CustomCarLink.h"

//int temps = 0;

CustomCarLink::CustomCarLink(PinName tx, PinName rx, const char *name, int baud):Serial(tx, rx, name, 115200){}

int sendData(){
    return 0;  
}

int put(void* data, size_t size){
    return 0;
}
