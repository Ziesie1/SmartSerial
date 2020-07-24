# SmartSerial

Use Serial with practical functions.

## Easy way to concatenate numbers with strings
Example:
```cpp
#include <Arduino.h>
#include <SmartSerial.hpp>

using namespace utilities;
SmartSerial ss = SmartSerial(Serial);

void setup() {
  Serial.begin(9600);

  // example values
  double temp = 24.0;
  bool status = true;
  long time = millis();

  ss << "Temperature: " << temp << " °C" << ", status: " << status;
  ss << ", time: " << time << " ms" << ssEndl;
}

void loop() { }
```

Output:
```
Temperature: 24.00 °C, status: 1, time: 61 ms
```

## Use induviduel outputs formats
You can differentiate between various types of Messages.

Example:
```cpp
#include <Arduino.h>
#include <SmartSerial.hpp>

using namespace utilities;
SmartSerial sDebug = SmartSerial(Serial, "Debug/"," -> ");
SmartSerial sError = SmartSerial(Serial, "Error/"," # ");


void setup() {
  Serial.begin(9600);
 
  sDebug("setup()") << 20.0 << "° C" << ssEndl;
  sDebug.disable();
  sDebug("setup()") << "some other debug informations" << ssEndl; // will not displayed

  sError("setup()") << "Houston, we have a problem." << ssEndl;
}

void loop() { }
```

Output:
```
Debug/setup() -> 20.00° C
Error/setup() # Houston, we have a problem.
```

