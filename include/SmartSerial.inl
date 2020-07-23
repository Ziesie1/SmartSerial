#include "SmartSerial.hpp"

/*
    normal output message - without LF&CR
    (like the normal arduino Serial)
*/
template<typename T>
void SmartSerial::print(T const& message) const
{
    if(this->serial == nullptr)
    {
        return;
    }
    this->serial->print(message);
}

/*
    normal output message - with LF&CR
    (like the normal arduino Serial)
*/
template<typename T>
void SmartSerial::println(T const& message) const
{
    if(this->serial == nullptr)
    {
        return;
    }
    this->serial->println(message);
}

/*
    normal output message - without LF&CR
*/
template<typename T>
SmartSerial const& SmartSerial::operator<<(T const& message) const
{
    if(this->serial == nullptr)
    {
        return *this;
    }
    this->serial->print(message);
    return *this;
}
