#include "../include/modes/SmartDebug.hpp"

SmartDebug utilities::sd {};

SmartDebug::SmartDebug(){}

SmartDebug::SmartDebug(HardwareSerial& serial)
    :SmartSerial(serial)
{ }

SmartDebug const& SmartDebug::operator()(String const& tag) const
{
    this->print("D/");
    this->print(tag);
    this->print(" : ");

    return *this;
}