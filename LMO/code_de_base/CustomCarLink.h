#ifndef _CARLINK_H
#define _CARLINK_H

#include "mbed.h"

/*
Adapted from the CarLink of darkPhenix
*/

class CustomCarLink : public Serial{
    
    // Constructeur de l'objet, il passe juste tous ses parametres au constructeur de Serial
    public:CustomCarLink(PinName tx, PinName rx, const char *name=NULL, int baud = MBED_CONF_PLATFORM_DEFAULT_SERIAL_BAUD_RATE);
    
    //to send to the PC the pixels, speed and direction of this cycle
    public:int sendData();
    
    //generic function to send bytes
    private:int put(void* data, size_t size);
};

#endif //_CARLINK_H
