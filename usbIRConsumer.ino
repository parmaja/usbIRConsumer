/**
* usbIRConsumer read IR sensor pulses reader and send it as keyboard/consumer code
*
* @license   The MIT License (MIT) Included in this distribution
*
* @author:    Zaher Dirkey <zaherdirkey at yahoo dot com>
*
* References:
* https://arduino-info.wikispaces.com/IR-RemoteControl?responseToken=5bdb1124d8f0ee73e2f4400688d4e7f3
*/

//#define DEBUG //enable it to send out info over Serial, not work in attiny

#include <UsbKeyboard.h>
#include <miniIRemote.h>

/*
// IR sensor connected to PB0 = ATtiny85 physical pin 5
#define IRpin_PIN PINB
#define IRpin 0
*/

void sendNumber(uint32_t n) {
  char str[40];
  ultoa(n, str, 10);
  UsbKeyboard.sendString(str);
  UsbKeyboard.wait();
}

void setup() {
  TIMSK &= !(1 << TOIE0); // Disable timer0 as it can interfere with USB timing
  miniIR::init(0);  
}

uint32_t irLastCode = 0;

void loop() {   
    UsbKeyboard.delay();
    UsbKeyboard.update();
    
    uint32_t irCode = miniIR::Read(); // Wait for an IR Code        
    
    UsbKeyboard.update(); // needs to be called often    
    if (irCode == 1) {
      irCode = irLastCode;
    }
    
    if (irCode > 0) {
      irLastCode = irCode;
      if (irCode == 1086263535) { // Single character example, "1"
        UsbKeyboard.sendKeyStroke(KEY_1);
      } else if (irCode == 1086296175) {
        UsbKeyboard.sendKeyStroke(KEY_2);    
      } else if (irCode == 1086279855) {
        UsbKeyboard.sendKeyStroke(KEY_3);    
      } else if (irCode == 1086271695) {
        UsbKeyboard.sendKeyStroke(KEY_4);    
      } else if (irCode == 1086304335) {
        UsbKeyboard.sendKeyStroke(KEY_5);    
      } else if (irCode == 1086288015) {
        UsbKeyboard.sendKeyStroke(KEY_6);    
      } else if (irCode == 1086261495) {
        UsbKeyboard.sendKeyStroke(KEY_7);    
      } else if (irCode == 1086294135) {
        UsbKeyboard.sendKeyStroke(KEY_8);    
      } else if (irCode == 1086277815) {
        UsbKeyboard.sendKeyStroke(KEY_9);    
      } else if (irCode == 1086269655) {
        UsbKeyboard.sendKeyStroke(KEY_0);    
      } else if (irCode == 1086259455) {
        UsbKeyboard.sendConsumerStroke(CONSUMER_MUTE);
      } else if (irCode == 1086320655) {
        UsbKeyboard.sendConsumerStroke(CONSUMER_CHANNEL_INCREMENT);
      } else if (irCode == 1086310455) {
        UsbKeyboard.sendConsumerStroke(CONSUMER_CHANNEL_DECREMENT);
      } else if (irCode == 1086316575) {
        UsbKeyboard.sendConsumerStroke(CONSUMER_VOLUME_INCREMENT);
      } else if (irCode == 1086283935) {
        UsbKeyboard.sendConsumerStroke(CONSUMER_VOLUME_DECREMENT);
      }
      else {
        /*
        UsbKeyboard.sendString(" Code: ");      
        UsbKeyboard.update();
        sendNumber(irCode);*/
      }
    }
    UsbKeyboard.delay(); 
}

