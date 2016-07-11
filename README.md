### usbIRConsumer ###
Arduino/Attiny85 project, Infrared PC remote control receiver to PC computer through USB.
It is a electronic circuit and code project.

Based on Nathan  Tiny PC Remote  
https://nathan.chantrell.net/20121014/tinypcremote-an-attiny85-based-infrared-pc-remote-control/ 

##License##

The MIT License (MIT) 
https://opensource.org/licenses/MIT

##Tested##
	Attiny85 Arduino IDE 1.6 with common remote controls

##How to Compile##

First You need Arduino IDE 1.6 or over to compile.
Also you need to install two of library, and one board into your ide.

###Required Libraries###
https://github.com/parmaja/miniIRemote
https://github.com/parmaja/miniUsbKeyboard

###Attiny85 Board###
In IDE->File->Preferences->Additional Boards Manager URLs
Add this repository URL then click OK 
https://raw.githubusercontent.com/damellis/attiny/ide-1.6.x-boards-manager/package_damellis_attiny_index.json

Now in IDE->Tools->Board->Boards Manager, Find Attiny board library and install it, you can see the new board in your board menu.

##Upload to Attiny##
Be sure you uploaded a bootloader first (once) into your Attiny to set fuses to use External 16M cyrstal, that my circuit using it, but you can set it to internal 16M osclicator but at this situation you need to calebrate it. 


##How to contribute##
Easy, Correct my English language ;) 
Rport bugs, or Fork it.