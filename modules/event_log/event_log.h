#ifndef EVENT_LOG_H
#define EVENT_LOG_H

#include "mbed.h"

extern UnbufferedSerial uartUsb;

#define MAX_LOG_ENTRIES 100

void eventLogInit();
void eventLogAddEntry(const char* entry);
void eventLogPrint();
void printEventLog();

#endif // EVENT_LOG_H