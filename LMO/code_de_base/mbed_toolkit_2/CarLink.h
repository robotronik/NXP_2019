#ifndef _CARLINK_H
#define _CARLINK_H

#include "mbed.h"
#include "ToolkitTools.h"
#include "ToolkitServo.h"
#include "ToolkitMotors.h"
#include "ToolkitCamera.h"

extern float speedL;
extern float speedR;
extern float servoDirection;
extern unsigned int *scanLinePixels;

/*******************************************************************************
 *
 *  CarLink permet d'envoyer les données à l'interface sur le PC.
 * C'est un objet qui hérite (go google pour savoir ce que ça veut dire) de
 * l'objet sSerial.
 * Il suffit d'utiliser la methode sendData pour envoyer les données comme il
 * faut
 ******************************************************************************/

class CarLink : public Serial
{
public:
    // Constructeur de l'objet, il passe juste tous ses parametres au constructeur de Serial
    CarLink(PinName tx, PinName rx, const char *name=NULL, int baud = MBED_CONF_PLATFORM_DEFAULT_SERIAL_BAUD_RATE);

    // Fonction pour envoyer les données
    int sendData();
private:
    // Il exite pas de fonction générique pour envoyer des place d'octet facilement
    // donc j'en ai fait une :
    int put(void *whatever, size_t size);
};

#endif //_CARLINK_H


