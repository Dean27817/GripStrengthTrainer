//checks if this class is already defined
//just used for safety
#ifndef BLE_SIGNAL

//librarys that are included
//one for basic arduino functions and the other for Bluetooth
#include <Arduino.h>
#include <BleGamepad.h>

//used to set the name for the device
String bluetoothName = "GrippyMcGripsalot";

String CreatorName = "FRCC";

uint8_t Battery = 100;

//creates the bluetooth object
BleGamepad BLuetoothControll;

//Mainly used in the main program to have a simple way to call functions
class BLESignal
{
    public: 

    //this function is used to start the bluetooth connection
    void StartConnection(String bluetoothName)
    {
        BLuetoothControll.begin();
        while(!BLuetoothControll.isConnected());
        return;
    }

    //called to send the signal to the connected device
    void OnPress()
    {
        if(BLuetoothControll.isConnected())
        {
            BLuetoothControll.press(BUTTON_5);
        }
    }

    //called to send the off signal to the connected device
    void StopPress()
    {
        if(BLuetoothControll.isConnected())
        {
            BLuetoothControll.release(BUTTON_5);
        }
    }

    bool IsConnected()
    {
        return BLuetoothControll.isConnected();
    }
};
#endif