# GripStrengthTrainer

**Overview**<br>
This is code that is to be used on an ESP32-S3-ZERO as a part of a grip strength training tool. It will pair with an Android phone and have a button on the trainer that will be pressed when it is closed. this will send a signal to the phone via Bluetooth. It will show up as a game controller and send button 5 when pressed.


**Use**<br>
As Said before, you will need a button and the esp32-S3-ZERO. currently, the code is set up so the button will be soldered to pin 6, but this can be changed in the code. If you are using the code as written, solder the button to pin 6 and power the board. *Note that you must use the library that I have placed with this code, as the default library dosn't play well with my code, nor the board.* Make sure that the button is in a place that will be pressed when the trainer is closed, and you should be good!
