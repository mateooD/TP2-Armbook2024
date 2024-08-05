# Sistema de estacionamiento inteligente

## Trabajo Practico 2 - Curso Sistemas embebidos - ArmBook 2024

## Alumno : 
* Diaz Mateo - mateo99.d@gmail.com

## Profesores : 
- Ariel Lutenberg 
- Sergio Caprile  
- Juan Manuel Reta 
- Eduardo Filomena

## Descripción
Para esta segunda parte del proyecto, se pretende seguir con la misma idea que estamos trabajando, se añadadiran un par de modulos extras, pero lo fundamental en esta etapa se basa en los siguientes pilares : **Modularizacion**,**Uso de variables y funciones públicas y privadas** , **Diseño con bajo acoplamiento y alta cohesión**, **Máquina de estado finito**.
Este proyecto implementa un sistema de estacionamiento autonomo e inteligente utilizando la plataforma MBED. El objetivo ese llevar el control de un estacionamiento de vehiculos de manera autonoma. En esta primera instancia se simula el control de ingreso al establecimiento.
En esta segunda etapa el sistema se compone de 2 botones que simulan el ingreso(verde) y egreso(rojo) de los vehiculos, un teclado matricial para que el usario indique su patente o dominio de el vehiculo y la conexion del sistema por puerto serie a la pc.Siguen tambien conectados los leds rojo y verde , pero en este caso indicaran si un auto ingresa o egresa


## Desarrollo
### Circuito
El proyecto se basó en la placa de desarrollo STM32F4, en particular el modeloSTM32F401RE. La misma cuenta con un microcontrolador STM32F401RET6, el cual posee un núcleo ARM Cortex-M4. El resto de componentes se planteo en una protoboard como se mostrara en siguientes imagenes.

#### Placa de desarrollo:
*NUCLEO_F401RE

![placa_desarrollo](https://github.com/mateooD/TP2-Armbook2024/blob/Revision_tp2/figures/placa_desarrollo.png)

Podemos plantear un diagrama como el siguiente:

![diagrama_bloques](https://github.com/mateooD/TP2-Armbook2024/blob/Revision_tp2/figures/bloques%20tp2.png)

## Estructura archivos fuente
```
Proyecto_Sistema_Estacionamiento_Inteligente/
├── main.cpp
├── smart_parking_system/
│   ├── smart_parking_system.cpp
│   └── smart_parking_system.h
├── pc_serial_com/
│   ├── pc_serial_com.cpp
│   └── pc_serial_com.h
├── matrix_keyboard/
│   ├── matrix_keyboard.cpp
│   └── matrix_keyboard.h
├── led_control/
│   ├── led_control.cpp
│   └── led_control.h
├── button_control/
│   ├── button_control.cpp
│   └── button_control.h
├── event_log/
│   ├── event_log.cpp
│   └── event_log.h
├── patente_capture/
│   ├── patente_capture.cpp
│   └── patente_capture.h

```

### Funcionamiento

En primer lugar se pretende que el sistema arranque apagado, y se espera que se presione un boton. Una vez hecho eso, el sistema pedirá en este caso que se ingrese el dominio o patente de el vehiculo.Se simulara enotnces la salida y entrada de vehiculos con botones,  se dará detalle de lo mismo por comunicacion serial a la pc. Todos estos datos se van guardando en un event log.
Con el boton de reset la idea es imprimir en pantalla de la pc el detalle de que auto ingreso o egreso de el lugar. 
La alimentacion de todo el sistema en este caso se utilizaron las salidas de 3,3v y GND de la placa. 

#### Mejoras a futuro
En un futuro se pretende utilizar un modulo extra ya que la idea es añadir un display lcd que interactue con el usario de el sistema. Ademas se pretende configurar el RTC (Real Time Clock), para que se detalle y se tenga en cuenta el dia y horario de la salida y entrada de el vehiculo.
Tambien se podria añadir guardar dichos eventos en una sd card o enviarlos vía Bluethoot o Wi-Fi.


### Perifericos a utilizar:
- **Button Reset** : Inicio del sistema 
- **Button Green** : Ingreso vehiculo
- **Button Red** : Egreso vehiculo
- **Led Green** : Vehiculo ingresando
- **Led Red** : Vehiculo Egresando
- **Matrix Keyboard** : Ingreso de dominio al sistema
- **Uart** : Comunicación con PC



## Imagenes del circuito y funcionamiento

### Imagenes circuito
Auto ingresando:
![car_in](https://github.com/mateooD/TP2-Armbook2024/blob/Revision_tp2/figures/in.jpeg)

Auto Egresando
![car_out](https://github.com/mateooD/TP2-Armbook2024/blob/Revision_tp2/figures/out.jpeg)

### Comunicacion serial PC

Secuencia ingreso y egreso de vehiculo

![car_in_out_pc](https://github.com/mateooD/TP2-Armbook2024/blob/Revision_tp2/figures/in_and_out.png)

Impresion Event log :

![event_log](https://github.com/mateooD/TP2-Armbook2024/blob/Revision_tp2/figures/eventlog.png)


### Video Funcionamiento
:construction: En proceso :construction:

## Codigo
En el repositorio se encuentran el archivo main, junto con las librerias necesarias para el funcionamiento. Ademas como se mencionó antes, el codigo se encuentra modularizado para 
Esta en desarrollo la documentacion con ***Doxygen***.

:construction: En proceso :construction: