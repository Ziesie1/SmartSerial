#include <Arduino.h>
#include <unity.h>

#include "SmartSerial.hpp"

using namespace utilities;

/**
 * declarations of all test functions
*/
void test_makros();

void setup() {
    Serial.begin(9600);

    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    // delay(2000);

    UNITY_BEGIN();
    RUN_TEST(test_makros);
    UNITY_END();
}

void loop() {
}

String helper_filePosition(String const& file, int line) {
    return file + ":" + line;
}

void test_makros() {
    String currentFunctionName = SS_FUNC;
    String currentFileposition = helper_filePosition(SS_POS);

    TEST_ASSERT_TRUE(currentFunctionName.equals("test_makros()"));
    TEST_ASSERT_TRUE(currentFileposition.equals("test_main.cpp:34"));
}

