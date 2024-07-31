#include "led_control.h"
#include "mbed.h"

DigitalOut led(LED1); // LED1 es el LED integrado en la mayoría de las placas mbed

void ledControlInit() {
    led = 0; // Asegura que el LED esté apagado al inicio
}

void ledToggle() {
    led = !led; // Cambia el estado del LED
}