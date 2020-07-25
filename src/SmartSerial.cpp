#include <SmartSerial.hpp>

const String utilities::ssEndl = "\r\n"; // LF & CR
const String utilities::ssSpace = " "; // space

SmartSerial::SmartSerial(HardwareSerial& serial, const String & label, const String & separator)
    :serial {&serial}, label{label}, separator{separator}
{ }

/*
    This method set the HardwareSerial port.
*/
void SmartSerial::workWith(HardwareSerial& serial)
{
    this->serial = &serial;
}

SmartSerial const& SmartSerial::operator()(String const& tag) const
{
    if(this->isEnabled)
    {
        this->print(this->label);
        this->print(tag);
        this->print(this->separator);
    }
    return *this;
}

SmartSerial const& SmartSerial::operator()(String const& file, int line) const
{
    if(this->isEnabled)
    {
        this->print(this->label);
        this->print(file);
        this->print(":");
        this->print(line);
        this->print(this->separator);
    }
    return *this;
}

/*
    enable the Serial output
*/
void SmartSerial::enable()
{
    this->isEnabled = true;
}

/*
    disable the Serial output
*/
void SmartSerial::disable()
{
    this->isEnabled = false;
}
