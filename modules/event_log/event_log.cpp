#include "event_log.h"
#include "pc_serial_com.h"


static char eventLog[MAX_LOG_ENTRIES][200];
static int logIndex = 0;

void eventLogInit() {
    logIndex = 0;  // Inicializa el índice del registro
}

void eventLogAddEntry(const char* entry) {
    if (logIndex < MAX_LOG_ENTRIES) {
        snprintf(eventLog[logIndex], sizeof(eventLog[logIndex]), "%s", entry);
        logIndex++;
    }
}

void eventLogPrint() {
    for (int i = 0; i < logIndex; i++) {
        uartUsb.write(eventLog[i], strlen(eventLog[i]));
        uartUsb.write("\r\n", 2);
    }
}

void printEventLog() {
    uartUsb.write("Imprimiendo registro de eventos...\r\n", 36);
    eventLogPrint();  // Imprime el contenido del registro de eventos
    uartUsb.write("Fin del registro de eventos.\r\n", 30);
}