/*

  Copyright (c) 2012-2014 RedBearLab

  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/

/*
      HelloWorld

      HelloWorld sketch, work with the Chat iOS/Android App.
      It will send "Hello World" string to the App every 1 sec.

*/

//"RBL_nRF8001.h/spi.h/boards.h" is needed in every new project
#include <SPI.h>
#include <EEPROM.h>
#include <boards.h>
#include <RBL_nRF8001.h>
#include <RBL_services.h>

#include <Wire.h>
#include "I2Cdev.h"
#include "MPU6050.h"

void setup()
{
  //
  // For BLE Shield and Blend:
  //   Default pins set to 9 and 8 for REQN and RDYN
  //   Set your REQN and RDYN here before ble_begin() if you need
  //
  // For Blend Micro:
  //   Default pins set to 6 and 7 for REQN and RDYN
  //   So, no need to set for Blend Micro.
  //
  //ble_set_pins(3, 2);

  // Set your BLE advertising name here, max. length 10
  ble_set_name("LeftCompanion");

  // Init. and start BLE library.
  ble_begin();
  
  // Enable serial debug
  Serial.begin(38400);
}

unsigned char buf[16] = {0};
unsigned char len = 0;
bool collectingData = false;
void loop()
{
  
  //if ( ble_connected() && sendNow)
  //{
   // ble_write('H');
 // }
/*

  if ( ble_available() )
  {
    while ( ble_available() )
    {
      sendNow = true;
      Serial.write(ble_read());
    }

    Serial.println();
    
  }
*/
  
 if ( ble_connected() ) {
     if (ble_available()) {
       Serial.println(" I GOT A PACKET FROM CENTRAL");
       if (ble_read() == 'Y') {
         sendNow = true;
         Serial.println(" I GOT A START FROM CENTRAL");
         //collectingData = true;
       } else if (ble_read() == 'N') {
         Serial.println("I GOT A NO FROM CENTRAL");
         // collectingData = false;
         //Send buffered data over bluetooth then clear buffer
         //broadcastBuffer(true);
       }
    }
 }
  

  ble_do_events();
  delay(1000);
}


