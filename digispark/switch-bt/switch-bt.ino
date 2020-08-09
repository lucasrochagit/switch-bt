#include <SoftSerial.h> // manage serial data (bluetooth)
#include <Thread.h> // create threads
#include <ThreadController.h> // controller to manage multiple threads

SoftSerial mySerial(0, 1); // rx, tx
char buf;   // get data from serial
const int relay = 2; // port used on digispark to turn on/off the relay
const int lumSensor = 3; // port used to read the lum sensor info
const int pirSensor = 4; // port used to read the pir sensor info

int lumSensibility = 820; // threshold value of brightness. warning: this value is different, 
                          // based on the environment in which the circuit is working, so it 
                          // must be modified

bool isLumSensorEnabled = false; // controller to enable/disable lum sensor task
bool isPirSensorEnabled = false; // controller to enable/disable pir sensor task

ThreadController controller = ThreadController();

Thread lumSensorThread = Thread();
Thread pirSensorThread = Thread();

void setup(){
  /* serial setup, using the default baud for hc-05 bluetooth module */
  mySerial.begin(9600); 

  /* pins setup*/
  pinMode(relay, OUTPUT);
  pinMode(lumSensor, INPUT);
  pinMode(pirSensor, INPUT);

  /* thread setup */
  lumSensorThread.onRun(manageLumSensor);
  lumSensorThread.setInterval(2000); 

  pirSensorThread.onRun(managePirSensor); 
  pirSensorThread.setInterval(15);

  controller.add(&lumSensorThread);
  controller.add(&pirSensorThread);
}

void loop(){
  controller.run(); // runs the thread controller
  
  if (mySerial.available() > 0){
    buf = mySerial.read();
    
    if (buf == '0') { // command to turn off the relay
      digitalWrite(relay, LOW);
    }
    
    else if (buf == '1') { // command to turn on the relay
      digitalWrite(relay, HIGH);
    }

    else if (buf == 'l' || buf == 'L') { // command to enable/disable lum sensor task
      isLumSensorEnabled = !isLumSensorEnabled;
    }

    else if (buf == 'p' || buf == 'P') { // command to enable/disable pir sensor task
      isPirSensorEnabled = !isPirSensorEnabled;
    }
  }
}

/* method used on lum sensor thread.*/
void manageLumSensor() {
  if (isLumSensorEnabled) {  // verify if the task is runnable
    int value = analogRead(lumSensor); // read the lum sensor value
    mySerial.println(value);
    if (value > lumSensibility) { // if the value read for lum sensor is above the min sensibility
      digitalWrite(relay, HIGH); // it means that the environment is dark, so turn on the light
    } else { // otherwise
      digitalWrite(relay, LOW);   // turn off the light 
    }
    delay(50); // delay of fifty ms   
  } 
}

/* method used on pir sensor thread*/
void managePirSensor() {
  if (isPirSensorEnabled) { // verify if the task is runnable
    int value = digitalRead(pirSensor); // read the pir sensor value
    if (value == HIGH) { // if any presence is detected in the environment 
      digitalWrite(relay, HIGH); // turn on the relay 
      delay(5000); // for five seconds
      digitalWrite(relay, LOW); // and then turn off the relay
    }    
  }    
}
