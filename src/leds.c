/**
  ******************************************************************************
  * @file    Driver Leds
  * @author  Mario Aguilar Montoya 
  * @date    5/12/2021
  ******************************************************************************
  */

#include "leds.h"
#include "errores.h"

/*Definiciones de constantes*/

#define LEDS_ALL_OFF 0x0000
#define LEDS_ALL_ON 0xFFFF
#define LEDS_OFFSET 1
#define LED_ON_STATE 1

/*Variables globales */
static uint16_t *puerto;

/**
 * @brief Enmascara el bit del led deseado
 * 
 * @param led 
 * @return uint16_t 
 */
uint16_t LedToMask(int led)
{
    return (LED_ON_STATE << (led-LEDS_OFFSET));

}

/**
 * @brief Configurar la direccion del puerto 
 * 
 * @param direccion Direccion a asignar al puerto 
 */
void LedsCreate(uint16_t * direccion)
{
     puerto= direccion;
     *puerto=LEDS_ALL_OFF;
}

/**
 * @brief Prende un led en especifico del puerto 
 * 
 * @param led Led a prender
 */
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

/**
 * @brief Apaga un led en especifico del puerto 
 * 
 * @param led  Led a apagar 
 */
void LedsOff(int led)
{
    *puerto &=~LedToMask(led);
}

/**
 * @brief Prende todos los leds del puerto 
 * 
 */

void LedsOnAll()
{
    *puerto=LEDS_ALL_ON;
}

/**
 * @brief  Apaga todos los leds del puerto 
 */

void LedsOffAll()
{
    *puerto=LEDS_ALL_OFF;
}

/**
 * @brief Consulta el estado de un led  
 * 
 * 
 * @param led  Led a leer estado 
 */
void LedsState(uint16_t led)
{      
    if (*puerto & LedToMask(led))   
    {
        StatusLed("Led Encendido");
    }
    else
    {
        StatusLed("Led Apagado");
    }
}