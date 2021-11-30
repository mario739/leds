#include <stdint.h>

void LedsCreate(uint16_t *puerto);
void LedsOn(int led);
void LedsOff(int led);
void LedsOnAll();
void LedsOffAll();
void LedsState(uint16_t led);