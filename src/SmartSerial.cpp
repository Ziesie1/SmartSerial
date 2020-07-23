#include "../include/SmartSerial.hpp"

const String utilities::ssEndl = "\r\n"; // LF & CR
const String utilities::ssSpace = " "; // space
SmartSerial utilities::ss {}; // be of use for the projekt to manage the seriel communication

SmartSerial::SmartSerial()
{ }

SmartSerial::SmartSerial(HardwareSerial& serial)
    :serial {&serial}
{ }

/*
    This method set the HardwareSerial port.
*/
void SmartSerial::workWith(HardwareSerial& serial)
{
    this->serial = &serial;
}
