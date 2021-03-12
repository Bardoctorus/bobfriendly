
#include <EEPROM.h>

int addr = 0;
int endMem = 512; // Where to stop reading into eeeprom, 4096 is max

void setup() {
  Serial.begin(115200);
  Serial.println("EEPROM Test starting in 5 secs");
  delay(5000);
  for(int i= 0; i < 50; i++)
  {
    int value = EEPROM.read(addr);
    Serial.print(addr);
    Serial.print("\t");
    Serial.print(value, DEC);
    Serial.println();
    addr+=1;
  }

  addr = 0;

}

void loop() {

//  if (Serial.available() > 0) 
//  {
    // read the incoming byte:
    int incomingByte = analogRead(A0) / 4;

    // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingByte);
    EEPROM.write(addr, incomingByte);
    addr= addr + 1;

    if (addr == 512) 
    {
      addr = 0;
    }
    
    if (EEPROM.commit()) 
    {
      Serial.println("EEPROM successfully committed");
    } else {
      Serial.println("ERROR! EEPROM commit failed");
    }
//  }
    delay(100);
  
}
