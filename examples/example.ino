#include <Arduino.h>
#include <SmartSerial.hpp>

using namespace utilities; // instead of utilities::ssEndl

SmartSerial ss = SmartSerial(Serial);
SmartSerial sDebug = SmartSerial(Serial, "Debug/"," -> "); // Debug/TAG -> MESSAGE...
SmartSerial sError = SmartSerial(Serial, "Error/"," : "); // Error/TAG : MESSAGE...

void setup() {
  Serial.begin(9600);

  ss << "The temperature is " << 30.00 << " °C " << ssEndl;

  sError("setup()") << "Houston, we have a problem." << ssEndl;

  sDebug.disable();
  sDebug("setup()") << " " << 20.0 << "° C" << ssEndl; // will not displayed

}

/*
  Output:
  The temperature is 30.00 °C
  Error/setup() : Houston, we have a problem.
*/

void loop() { }