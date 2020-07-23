#ifndef SMART_DEBUG_HPP
#define SMART_DEBUG_HPP

#include <Arduino.h>
#include "../SmartSerial.hpp"

// sd("setup") << "" << ssEndl;

class SmartDebug : public SmartSerial
{
private:

public:
    SmartDebug();
    SmartDebug(HardwareSerial& serial);

    SmartDebug const& operator()(String const& tag) const;

};

namespace utilities
{
    extern SmartDebug sd;
}



#endif
