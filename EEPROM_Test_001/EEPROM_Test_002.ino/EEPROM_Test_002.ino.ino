/*
   EEPROM Write

   Stores values read from analog input 0 into the EEPROM.
   These values will stay in the EEPROM when the board is
   turned off and may be retrieved later by another sketch.
*/

#include <EEPROM.h>

// the current address in the EEPROM (i.e. which byte
// we're going to write to next)
int addr = 0;
bool done = 0;
void setup() {
  Serial.begin(115200);
  EEPROM.begin(512);
}

void loop() {
  // need to divide by 4 because analog inputs range from
  // 0 to 1023 and each byte of the EEPROM can only hold a
  // value from 0 to 255.
  
  if(Serial.available() > 0)
  {

//     if(Serial.readString() == "done")
//    {
//  
//      Serial.println("done");
//      done = 1; 
//    }
     int val = Serial.read();
     Serial.println(val);
  // write the value to the appropriate byte of the EEPROM.
  // these values will remain there when the board is
  // turned off.
  EEPROM.write(addr, val);
  addr = addr + 1;
  }

 

  // advance to the next address.  there are 512 bytes in
  // the EEPROM, so go back to 0 when we hit 512.
  // save all changes to the flash.
 
  if (addr == 40) {
    addr = 0;
    if (EEPROM.commit()) {
      Serial.println("EEPROM successfully committed");
    } else {
      Serial.println("ERROR! EEPROM commit failed");
    }
  }

  delay(100);
}
