#include "leds.h"
#include "errores.h"

#define LEDS_ALL_OFF 0x0000
#define LEDS_ALL_ON 0xFFFF
#define LEDS_OFFSET 1
#define LED_ON_STATE 1
static uint16_t *puerto;


uint16_t LedToMask(int led)
{
    return (LED_ON_STATE << (led-LEDS_OFFSET));

}
void LedsCreate(uint16_t * direccion)
{
     puerto= direccion;
     *puerto=LEDS_ALL_OFF;
}
void LedsOn(int led)
{
    if ((led>=1) && (led<=16)) 
    {
        *puerto |=LedToMask(led);    
    }
    else
    {
        RegistraMensaje(0,__FUNCTION__,__LINE__,"Numero de led invalido");
    }
    
}
void LedsOff(int led)
{
    *puerto &=~LedToMask(led);
}

void LedsOnAll()
{
    *puerto=LEDS_ALL_ON;
}

void LedsOffAll()
{
    *puerto=LEDS_ALL_OFF;
}

void LedsState(uint16_t led)
{      
    if ((*puerto & (1<<(led-1))))   
    {
        StatusLed("Led Encendido");
    }
    else
    {
        StatusLed("Led Apagado");
    }
}