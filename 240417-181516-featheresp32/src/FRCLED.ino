//this is a program that will be put into a grip trainer to send signals to an app to count the ammount of times it is used

//library used to connect over bluetooth
#include "BLESignal.h"

//this is the pin that the button should be solderd to
//the other side of the button should be solderd to the GND pin
#define buttonPin 6


//creates the object of the bluetooth controller
BLESignal Bluetooth;

//the code put inside these brackets will run once when the board gets power
void setup() {
  //tells the board to look for a button on the button pin defined above
  pinMode(buttonPin, INPUT_PULLUP);

//this starts the communication with the computer, not the phone. anything written with this can only be seen if the board is plugged into the computer via usb
  Serial.begin(9600);

  Serial.println("Ready to connect");

  //starts the bluetooth server
  Bluetooth.StartConnection(bluetoothName);

  Serial.println("Connected");
}




void loop() {
  if(digitalRead(buttonPin) == 1)
  {
    //will print something to the computer if the button is not pressed
    Serial.println("the button is not pressed");
    Serial.println(digitalRead(6));
  }
  else
  {
    //prints to the computer if the button is not pressed
    Serial.println("PRESSED!!!!!!");  
    //sends the command to the paird device that the button was pressed
    Bluetooth.OnPress();
    //if the button is held down this will stop the program so it dosn't keep sending the signal to increase the counter.
    //this way it will only increase once    
    while(digitalRead(buttonPin) == 0)
    {
      sleep(1);
      Serial.println(digitalRead(6));
    }
    //stops sending the device the pressed command
    Bluetooth.StopPress();
  }
}
