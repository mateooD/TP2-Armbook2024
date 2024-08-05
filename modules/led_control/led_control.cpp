#include "led_control.h"
#include "mbed.h"

#define LED_GREEN_PIN D10
#define LED_RED_PIN D11

DigitalOut led(LED1); // LED1 es el LED integrado en la mayoría de las placas mbed
DigitalOut greenLed(LED_GREEN_PIN);
DigitalOut redLed(LED_RED_PIN);

void ledControlInit() {
    led = 0; // Asegura que el LED esté apagado al inicio
    greenLed = 0;
    redLed = 0;
}

void ledToggle() {
    led = !led; // Cambia el estado del LED
}

void turnOnGreenLed()
{
    greenLed = 1; // Enciende el LED verde
}


void turnOffGreenLed()
{
    greenLed = 0; // Apaga el LED verde
}

void turnOnRedLed()
{
    redLed = 1; // Enciende el LED rojo
}

void turnOffRedLed()
{
    redLed = 0; // Apaga el LED rojo
}

