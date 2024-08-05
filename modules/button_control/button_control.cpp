#include "button_control.h"
#include "mbed.h"

// Definir los pines de los botones
#define BUTTON_INGRESS_PIN D12
#define BUTTON_EGRESS_PIN  D13

// Crear objetos DigitalIn para los botones
DigitalIn buttonIngress(BUTTON_INGRESS_PIN);
DigitalIn buttonEgress(BUTTON_EGRESS_PIN);
DigitalIn buttonB1(BUTTON1);

void buttonControlInit() {
    buttonIngress.mode(PullDown); // Asegura que los botones estén en modo pull-up
    buttonEgress.mode(PullDown);
}


bool isIngressButtonPressed() {
    return buttonIngress.read();  // Retorna true si el botón está presionado (alto)
}

bool isEgressButtonPressed() {
    return buttonEgress.read();   // Retorna true si el botón está presionado (alto)
}

bool isButtonB1Pressed() {
    return !buttonB1.read();  // Retorna true si el botón está presionado (ajusta según tu configuración)
}