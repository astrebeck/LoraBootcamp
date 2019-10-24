//*** ----> LoRa parameters here:
#define  DEVEUI "3ef5c8309b11486a" // Put your 16 hex char here
#define  APPEUI "c2f028c662d84f00" // Put your 16 hex char here
#define  APPKEY "c2f028c662d84f1b9424a730172507e3" // Put your 32 hex char here
//*** <---- END LoRa parameters

//Include libraries 
#include "mQspark.h"

//*** Define in which port the temp sensor is plugged in ---->
int tempSensorPin = A1;     // Grove - Temperature Sensor connects to port closest to USB port
int pressureSensorPin = A3;    // Grove - Sound Sensor connect to the second closed port.

//Set device baud rate
long defaultBaudRate = 19200;

void setup() {
  sparkStart(defaultBaudRate,DEVEUI,APPEUI,APPKEY);
  mQjoin();
}

void loop() {
    //send LoRa packet
    float temperature = sparkTemp(tempSensorPin);
    float pressure = sparkPressure(pressureSensorPin);
    mQsend(8,lppVals(temperature, pressure ));
    delay(15000);
}
