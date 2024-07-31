//=====[Libraries]=============================================================

#include "arm_book_lib.h"
#include "matrix_keyboard.h"
#include "led_control.h"
#include "smart_parking_system.h"

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
  matrixKeyboardInit(40);
  ledControlInit();
}

void smartParkingUpdate() {
    char key = matrixKeyboardUpdate();
    if (key != '\0') {
        ledToggle(); // Toggle the LED integrated into the board each time a key is pressed
    }
    delay(100); // Wait for 100 ms

}

//=====[Implementations of private functions]==================================