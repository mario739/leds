#include "unity.h"
#include "leds.h"
#include "mock_errores.h"

/*Definiciones de constantes*/
#define LED 3
#define LED_BIT(x) (1<<(x-1))

    /*Variables globales */
static uint16_t puertoVirtual;

    /*Funcion añade el codigo al inicio de cada test*/
void setUp(void)
{
       LedsCreate(&puertoVirtual);
}

/* Despues de la configuracion todos los leds deben quedar apagados*/
void test_todos_los_leds_inician_apagados(void)
{
   uint16_t puertoVirtual=0xFFFF;
   LedsCreate(&puertoVirtual);
   TEST_ASSERT_EQUAL_HEX16(0x0000,puertoVirtual);
}
/* Prender un led cualquiera */
void test_prender_un_led(void)
{
    LedsOn(LED);
    TEST_ASSERT_EQUAL_HEX16(LED_BIT(LED),puertoVirtual);
}
 /*Apagar un led cualquiera*/
 void test_apagar_led(void)
{
    LedsOn(LED);
    LedsOff(LED);
    TEST_ASSERT_EQUAL_HEX16(0x0000,puertoVirtual);
}
/* Prender y apagar algunos leds */
void test_prender_y_apagar_varios_leds(void)
{
    LedsOn(LED);
    LedsOn(LED+3);
    LedsOff(LED);
    TEST_ASSERT_EQUAL_HEX16(LED_BIT(LED+3),puertoVirtual);
}
/* Prender todos los leds juntos */
void test_prender_todos_los_leds_juntos(void)
{
    LedsOnAll();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF,puertoVirtual);
}

/* Apagar todos los leds juntos */
void test_apagar_todos_los_leds_juntos(void)
{
    LedsOnAll();
    LedsOffAll();
    TEST_ASSERT_EQUAL_HEX16(0x0000,puertoVirtual);
}

/* Consultar el estado de un led apagado */
 void test_consultar_el_estado_de_un_led_apagado(void)
{ 
    StatusLed_Expect("Led Apagado");
    LedsOnAll();
    LedsOff(LED);
    LedsState(LED);
}

/* Consultar el estado de un led encendido */
 void test_consultar_el_estado_de_un_led_encendido(void)
{ 
    StatusLed_Expect("Led Encendido");
    LedsOn(LED);
    LedsState(LED);
}

/* Probar valores invalidos para los parametros */

void test_error_en_parametros(void)
{
    RegistraMensaje_Expect(0,"LedsOn",0,"Numero de led invalido");
    RegistraMensaje_IgnoreArg_linea();
    LedsOn(17);
}
