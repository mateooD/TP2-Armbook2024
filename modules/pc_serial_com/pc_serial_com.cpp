//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"
#include "pc_serial_com.h"
#include "matrix_keyboard.h"
#include "led_control.h"
#include "button_control.h"
#include "patente_capture.h"



//=====[Declaration of private defines]========================================
#define MAX_PATENTE_LENGTH 6


//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

UnbufferedSerial uartUsb(USBTX, USBRX, 9600);

//=====[Declaration of external public global variables]=======================
char patente[MAX_PATENTE_LENGTH + 1]; // +1 para el carácter de terminación '\0'
int patenteIndex = 0;

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============


static bool codeComplete = false;


//=====[Declarations (prototypes) of private functions]========================

static void pcSerialComStringRead(char* str, int strLength);
static void pcSerialComCommandUpdate(char receivedChar);

static void handleMatrixKeyboard();

//=====[Implementations of public functions]===================================

void pcSerialComInit()
{
    uartUsb.write("Sistema de Estacionamiento Inteligente Iniciado.\r\n", 56);
    delay(2000);
}

void pcSerialComButton()
{
    uartUsb.write("Presione el boton verde para ingresar o el boton rojo para egresar.\r\n", 73);
}


void pcSerialComUpdate() {
    if (isIngressButtonPressed()) {
        uartUsb.write("Vehiculo ingresando. Ingrese la patente:\r\n", 42);
        capturePatente(); // Llama al nuevo módulo para capturar la patente
        pcSerialComButton();
    } else if (isEgressButtonPressed()) {
        uartUsb.write("Vehiculo egresando. Ingrese la patente:\r\n", 42);
        capturePatente(); // Llama al nuevo módulo para capturar la patente
        pcSerialComButton();
    }
}

// Enviar una cadena a través del puerto serial
static void pcSerialComStringWrite(const char* str) {
    uartUsb.write(str, strlen(str));
}

// Manejo del teclado matricial para ingresar dominios/patentes
static void handleMatrixKeyboard() {
    char key = matrixKeyboardUpdate(); // Leer el carácter del teclado matricial

    if (key != '\0') { // Si se ha presionado una tecla
        if (patenteIndex < MAX_PATENTE_LENGTH) {
            patente[patenteIndex++] = key; // Guardar el carácter en la variable
            patente[patenteIndex] = '\0';  // Añadir terminador nulo
        }

        ledToggle(); // Opcional: Toggle del LED para indicar que se ha ingresado una tecla

        if (patenteIndex == MAX_PATENTE_LENGTH) {
            // Enviar la patente completa por comunicación serial
            pcSerialComStringWrite("Patente: ");
            pcSerialComStringWrite(patente);
            pcSerialComStringWrite("\r\n");

            // Guardar el dominio en el registro de eventos
            //eventLogSave(patente);

            patenteIndex = 0; // Reiniciar el índice para la siguiente entrada
        }
    }
}

