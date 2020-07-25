#ifndef SMART_SERIAL_HPP
#define SMART_SERIAL_HPP

#include <Arduino.h>
#include <string.h>

class SmartSerial
{
    HardwareSerial* serial;
    bool isEnabled = true;
    const String label = "";
    const String separator = "";
    
public:
    SmartSerial(HardwareSerial& serial, const String & label = "D/", const String & separator = " : ");
    
    void workWith(HardwareSerial& serial);

    template<typename T>
    void print(T const& message) const ;
    template<typename T>
    void println(T const& message) const;
    template<typename T>
    SmartSerial const& operator<<(T const& message) const;
    SmartSerial const& operator()(String const& tag) const;
    SmartSerial const& operator()(String const& file, int line) const;

    void enable();
    void disable();

};

#define POS __FILE__,__LINE__
#define FUNC ((String)__FUNCTION__)+"()"

namespace utilities
{
    extern const String ssEndl;
    extern const String ssSpace;
}

#include "SmartSerial.inl"


#endif
