#include "CarLink.h"

int temps = 0;
CarLink::CarLink(PinName tx, PinName rx, const char *name, int baud) :
    Serial(tx, rx, name, 115200)
{
}

int CarLink::sendData()
{
    // On envoie ces 4 octets pour indiquer le début de la trame
    unsigned char deadBeef[] = {222, 173, 190, 239};
    put((void *)deadBeef, 4);

    put((void *)scanLinePixels, 128*sizeof(unsigned int));
    //put((void *)pic_pos, 128*sizeof(uint16_t));
    //put((void *)&servoDirection, sizeof(float));
    //float moy= (speedL+speedR)/2.0;
    //put((void *)&moy, sizeof(moy));
    return 0;
}


int CarLink::put(void *whatever, size_t size)
{
    unsigned char *dec = (unsigned char *) whatever;
    unsigned int ret = 0, i;
    lock();
    fflush(_file);
    for (i = 0 ; i < (unsigned int)size ; i++)
    {
        ret += std::fputc(*(dec+i), _file);
    }
    unlock();
    return ret==(unsigned int)size;
}

