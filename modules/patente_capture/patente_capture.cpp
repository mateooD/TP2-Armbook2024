#include "mbed.h"
#include "matrix_keyboard.h"
#include "pc_serial_com.h"
#include "patente_capture.h"
#include "button_control.h"
#include "event_log.h"


#define MAX_PATENTE_LENGTH 6
#define TIMEOUT_MS 10000 // Tiempo límite de 10 segundos para capturar la patente

extern UnbufferedSerial uartUsb; // Reutilizar el objeto Serial de pc_serial_com

void capturePatente() {
    char patente[MAX_PATENTE_LENGTH + 1] = {0};
    int patenteIndex = 0;
    Timer timer;
    timer.start();

    uartUsb.write("Ingrese la patente:\r\n", 23);

    if (isIngressButtonPressed()) {
        eventLogAddEntry("Ingreso - Patente: ");
    } else if (isEgressButtonPressed()) {
        eventLogAddEntry("Egreso - Patente: ");
    } else {
        uartUsb.write("Error: Ningún botón de ingreso o egreso detectado.\r\n", 51);
        return; // Sale de la función si no se detecta el botón
    }

    while (timer.read_ms() < TIMEOUT_MS) {
        char key = matrixKeyboardUpdate();

        if (key != '\0') {
            patente[patenteIndex++] = key;
            uartUsb.write(&key, 1);

            if (patenteIndex == MAX_PATENTE_LENGTH) {
                break;
            }
        }
    }

    timer.stop();

    patente[patenteIndex] = '\0';
    
    uartUsb.write("\r\nPatente capturada: ", 22);
    uartUsb.write(patente, patenteIndex);
    uartUsb.write("\r\n", 2);

    // Registra la patente en el log
    eventLogAddEntry(patente);
    eventLogAddEntry("\r\n");
}