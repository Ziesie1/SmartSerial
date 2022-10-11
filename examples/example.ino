#include <Arduino.h>
#include <SmartSerial.hpp>

using namespace utilities; // instead of utilities::ssEndl

SmartSerial ss (Serial);
SmartSerial sDebug (Serial, "Debug/"," -> "); // Debug/TAG -> MESSAGE...
SmartSerial sError (Serial, "Error/"," # "); // Error/TAG : MESSAGE...

void setup() {
  Serial.begin(9600);

  // example values
  double temp = 24.0;
  bool status = true;
  long time = millis();

  ss << "Temperature: " << temp << " °C" << ", status: " << status << ", time: " 
     << time << " ms" << ssEndl;

  sDebug(SS_FUNC) << 20.0 << "° C" << ssEndl;
  sDebug.disable();
  sDebug(SS_POS) << "some other debug informations" << ssEndl; // will not displayed

  sError(SS_POS) << "Houston, we have a problem." << ssEndl;
}

/*
  Output:
  Temperature: 24.00 °C, status: 1, time: 65 ms
  Debug/setup() -> 20.00° C
  Error/main.cpp:25 # Houston, we have a problem.
*/

void loop() { }
