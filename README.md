# Bob Friendly Playground

this is where I mess about with fully ripped Arduino code from various tutorials to hack the idea together. 

So far we have:
- Messed about making an AP so we have an easy way to get details from the user (like wifi details)
- Failed to save to the EEPROM which is probably the easiest (but not best) way to save the user details

Next we need to:

- Make a simple web interface to take the user details
- Save them into EEPROM
- Create STATE dependent on button press when booting - if it's held, go into AP mode. If not, normal boot
- Use EEPROM details to connect to WiFi
- Make a test server to talk to
- Send some values

Currently I'm using a Wemos D1 mini, I was using a larger Node MCU with the esp8266mod chip (which is the same as the 12E right?) but it wouldn't play nice with eeprom. 

# What's happening now?

- Serial reads in to EEPROM, reads out and puts in char array, so text is preserved. This will likely be simpler when using web server.

# Things to think about

The ESP8266 only has one Analog input - does that matter? could multiplex as it's alwaysgoing to be delayed by connection even in same room.

How to test output for now? PWM? Look into cheap multi DAC boards? How do those cheap nano midi to CV things work.
