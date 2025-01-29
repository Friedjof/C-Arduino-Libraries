#include "JsonProperties.h"


void debugTable();
void setup() {
    Serial.begin(9600); // Start Serial Connection

    JsonProperties properties;
    properties.init("key1", PropertyType::INT);
    properties.initLong("key2", 0, 100);
    properties.init("key3", PropertyType::FLOAT);
    properties.init("key4", PropertyType::DOUBLE);
    properties.init("key5", PropertyType::STRING);
    properties.init("key6", PropertyType::COLOR);
    properties.init("key7", PropertyType::BOOL);

    properties.initInt("key8", 10);

    properties.getInt("key1");
}



void loop(){

}
