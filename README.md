 Switch BT

A project that uses electronics artifacts to make a switch controlled via bluetooth - and other features.

## Main Features

* Turn on and turn off a lamp through the smartphone via bluetooth;
* Program the circuit to turn a lamp on or off based on the ambient light level;
* Program the circuit to turn on a lamp for a period of time, if a presence is detected in the environment.

**Note**: this is a prototype project. To reproduce it in a domestic setting, it may be necessary to add other resources to the electronic circuit.

### Prerequisites
It is important that you have knowledge in microcontroller programming, and experience in assembling circuits. 

To program the microcontroller, it is recommended to use the Arduino IDE, and [install the Digispark Attiny board](https://www.instructables.com/id/Digispark-Attiny-85-With-Arduino-IDE) in the Arduino IDE (if you are going to use a Digispark Attiny).

To reproduce this project, you will need:

* 1x 800 Holes Breadboard
* 1x Digispark Attiny *
* 1x HC-05 Bluetooth Module
* 1x 5V Relay Module 1 Channel
* 1x PIR Presence Sensor Module
* 1x 5mm LDR (Brightness Sensor)
* 1x 100 ohm resistor
* 1x 150 ohm resistor
* 2x 10k ohm resistor
* 1x 2N2222 NPM Transistor
* 1x 5V Power Supply HLK-PM01 100-240V or similar **
* 1x Bulb 9W Bivolt
* 3x 2 way KRE terminal connector
* Jumpers (rigid or flexible)***
* 1x Smartphone with bluetooth 4.0 connection (Android operating system is required, Version 8.0 or higher)


\* Note: You can choose another microcontroller of your choice. However, you may need to make some changes to the code.<br/>
** You can use another source model, as long as the DC output voltage is equal to 5v.<br/>
*** Some jumpers will be used to transmit AC voltage. Make sure that the jumpers used for this purpose support the AC voltage.<br/>


### Installing

#### I - Smartphone

To install the app on your phone, download the app via this [link](https://github.com/lucasrochagit/switch-bt/blob/v1/app/InterruptorBluetooth.apk) and install the app on your phone. You may need to configure permission to install third-party applications on your smartphone.

#### II - Digispark Attiny

To install the application on the microcontroller, make sure that the Digispark Attiny board is properly configured in the Arduino IDE. After that, follow these steps:

1. Open the `switch-bt.ino` file located in `/digispark/switch-bt`
2. Then Click on `Tools -> Board -> Digistump AVR Boards` and select `Digispark (Default - 16.5MHz)`
3. Then click on `Sketch -> Upload`
4. After that, connect Digispark Attiny to any USB port on your computer and wait for the program to be recorded completely.

If the program is successfully recorded, a message will appear in the terminal: `>> Micronucleus done. Thank you! `


### Before All

**Important**:
1. Make sure that the circuit is **disconnected** from the mains before carrying out the assembly.
2. Make sure to record the program on Digispark Attiny before inserting it into the circuit.
 
### Assembling of the electronic circuit

The circuit can be assembled according to the image below:


![Circuit](https://github.com/lucasrochagit/switch-bt/blob/v1/images/circuit.png)



**Connection of digispark ports:**

* D0 -> TX (Bluetooth Module)
* D1 -> RX (Bluetooth Module)
* D2 -> Transistor Base
* D3 -> LDR sensor
* D4 -> PIR sensor

Usage video: coming soon! 

## Built With

* [Arduino IDE](http://arduino.cc) - The framework used

## Authors

* **Lucas Rocha** - *Initial work* 

## License

This project is licensed under the Apache License - see the [LICENSE.md](LICENSE) file for details

