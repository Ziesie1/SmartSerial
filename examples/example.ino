#include <Arduino.h>
#include <SmartSerial.hpp>

using namespace utilities; // instead of utilities::ssEndl

SmartSerial ss = SmartSerial(Serial);
SmartSerial sDebug = SmartSerial(Serial, "Debug/"," -> "); // Debug/TAG -> MESSAGE...
SmartSerial sError = SmartSerial(Serial, "Error/"," # "); // Error/TAG : MESSAGE...

void setup() {
  Serial.begin(9600);

  // example values
  double temp = 24.0;
  bool status = true;
  long time = millis();

  ss << "Temperature: " << temp << " °C" << ", status: " << status;
  ss << ", time: " << time << " ms" << ssEndl;

  sDebug("setup()") << 20.0 << "° C" << ssEndl;
  sDebug.disable();
  sDebug("setup()") << "some other debug informations" << ssEndl; // will not displayed

  sError("setup()") << "Houston, we have a problem." << ssEndl;
}

/*
  Output:
  Temperature: 24.00 °C, status: 1, time: 61 ms
  Debug/setup() -> 20.00° C
  Error/setup() # Houston, we have a problem.
*/

void loop() { }
