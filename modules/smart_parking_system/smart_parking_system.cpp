//=====[Libraries]=============================================================

#include "arm_book_lib.h"
#include "matrix_keyboard.h"
#include "led_control.h"
#include "smart_parking_system.h"
#include "pc_serial_com.h"
#include "button_control.h"
#include "event_log.h"


#include "mbed.h"


//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================


void smartParkingInit()
{
    pcSerialComInit();
    pcSerialComButton();
    buttonControlInit();
    matrixKeyboardInit(40);
    ledControlInit();
    eventLogInit();  
  
}
  

// Actualización del sistema de estacionamiento
void smartParkingUpdate() {
  if (isIngressButtonPressed() || isEgressButtonPressed()) {
        pcSerialComUpdate();
    }

 if (isButtonB1Pressed()) {
        printEventLog();
    }

}


//=====[Implementations of private functions]==================================