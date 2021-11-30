#include <stdint.h>


/* Inicializa el puerto */
void LedsCreate(uint16_t *puerto);

/*Funcion para prender un led */
void LedsOn(int led);

/*Funcion para apagar un led */
void LedsOff(int led);

/*Funcion para prender todos los leds al mismo tiempo  */
void LedsOnAll();

/*Funcion para apagar todos los leds al mismo tiempo */
void LedsOffAll();

/*Funcion para obtener el estado de un led en particular */
void LedsState(uint16_t led);