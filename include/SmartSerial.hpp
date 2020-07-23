#ifndef SERIAL_COMMUNKATION_HPP
#define SERIAL_COMMUNKATION_HPP

#include <Arduino.h>
#include <string.h>

class SmartSerial
{
    HardwareSerial* serial;
    
public:
    SmartSerial();
    SmartSerial(HardwareSerial& serial);
    
    void workWith(HardwareSerial& serial);

    template<typename T>
    void print(T const& message) const ;
    template<typename T>
    void println(T const& message) const;
    template<typename T>
    SmartSerial const& operator<<(T const& message) const;

};


namespace utilities
{
    extern const String ssEndl;
    extern const String ssSpace;
    extern SmartSerial ss;
}

#include "SmartSerial.inl"


#endif
