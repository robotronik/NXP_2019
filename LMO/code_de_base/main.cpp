#include "mbed.h"
#include "RobotronikToolkit.h"

void init();
bool loop();

int main(){
    //init
    initToolkit();
    init();
    
    //loop
    while(loop()){
        updateToolkit();
    };
}

void init(){
    
}

bool loop(){
    testCamera();
    return true;
}
