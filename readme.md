# SmartSerial

Use Serial with practical functions.

## Easy way to concatenate primitives data types
Example:
```cpp
#include <Arduino.h>
#include <SmartSerial.hpp>

using namespace utilities;
SmartSerial ss (Serial);

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

## Use individual outputs formats
You can differentiate between various types of messages.

Example:
```cpp
#include <Arduino.h>
#include <SmartSerial.hpp>

using namespace utilities;
SmartSerial sDebug (Serial, "Debug/"," -> ");
SmartSerial sError (Serial, "Error/"," # ");


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

