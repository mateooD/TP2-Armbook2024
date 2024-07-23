#include "mbed.h"

//testing

int main()
{
    DigitalIn B1_USER(BUTTON1);

    DigitalOut LD2(LED2);

    while (true) {
        LD2 = B1_USER;
    }
}
