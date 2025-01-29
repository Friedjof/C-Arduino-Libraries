/**
 * JsonProperties.h - A simple library for managing properties in JSON format.
 * The perfect Library for managing properties in JSON format.
 * It might be useful for transferring data over the network or storing data in a file.
 * Every property will be validated against a set of rules (min, max, etc.)
 */

#ifndef JSONPROPERTIES_H
#define JSONPROPERTIES_H

#include <limits.h>
#include <Arduino.h>
#include <ArduinoJson.h>

#include "ArrayList.h"


enum PropertyType {
  INT = 0,
  LONG = 1,
  FLOAT = 2,
  DOUBLE = 3,
  STRING = 4,
  COLOR = 5,
  BOOL = 6,
  NONE = 7
};


class JsonProperties {
  private:
    // properties stores the actual values
    JsonDocument properties;
    // meta stores the metadata for each property (PropertyType, min, max, etc.)
    JsonDocument meta;
    // keys stores the keys for each property (for a faster lookup)
    ArrayList<String> keys;

    bool isColor(const char* value);
    size_t getSize();

  public:
    JsonProperties();

    // initialize the properties object
    bool init(const char *key, PropertyType type);

    bool initInt(const char *key, int defaultValue);
    bool initInt(const char* key, int min, int max);
    bool initInt(const char* key, int defaultValue, int min, int max);

    bool initLong(const char* key, long defaultValue);
    bool initLong(const char* key, long min, long max);
    bool initLong(const char* key, long defaultValue, long min, long max);

    bool initFloat(const char* key, float defaultValue);
    bool initFloat(const char* key, float min, float max);
    bool initFloat(const char* key, float defaultValue, float min, float max);

    bool initDouble(const char* key, double defaultValue);
    bool initDouble(const char* key, double min, double max);
    bool initDouble(const char* key, double defaultValue, double min, double max);

    bool initString(const char* key, const char* defaultValue);
    bool initColor(const char* key, const char* defaultValue);
    bool initBool(const char* key, bool defaultValue);

    // get the value of a property
    int getInt(const char* key);
    long getLong(const char* key);
    float getFloat(const char* key);
    double getDouble(const char* key);
    const char* getString(const char* key);
    const char* getColor(const char* key);
    bool getBool(const char* key);

    // set the value of a property
    bool setInt(const char* key, int value);
    bool setLong(const char* key, long value);
    bool setFloat(const char* key, float value);
    bool setDouble(const char* key, double value);
    bool setString(const char* key, const char* value);
    bool setColor(const char* key, const char* value);
    bool setBool(const char* key, bool value);

    // get min/max values of a property
    int getIntMin(const char* key);
    int getIntMax(const char* key);
    long getLongMin(const char* key);
    long getLongMax(const char* key);
    float getFloatMin(const char* key);
    float getFloatMax(const char* key);
    double getDoubleMin(const char* key);
    double getDoubleMax(const char* key);

    // set min/max values of a property
    bool setIntBounds(const char* key, int min, int max);
    bool setIntMin(const char* key, int min);
    bool setIntMax(const char* key, int max);
    bool setLongBounds(const char* key, long min, long max);
    bool setLongMin(const char* key, long min);
    bool setLongMax(const char* key, long max);
    bool setFloatBounds(const char* key, float min, float max);
    bool setFloatMin(const char* key, float min);
    bool setFloatMax(const char* key, float max);
    bool setDoubleBounds(const char* key, double min, double max);
    bool setDoubleMin(const char* key, double min);
    bool setDoubleMax(const char* key, double max);

    // get default values of a property
    int getIntDefault(const char* key);
    long getLongDefault(const char* key);
    float getFloatDefault(const char* key);
    double getDoubleDefault(const char* key);
    const char* getStringDefault(const char* key);
    const char* getColorDefault(const char* key);
    bool getBoolDefault(const char* key);

    // set default values of a property
    bool setIntDefault(const char* key, int value);
    bool setLongDefault(const char* key, long value);
    bool setFloatDefault(const char* key, float value);
    bool setDoubleDefault(const char* key, double value);
    bool setStringDefault(const char* key, const char* value);
    bool setColorDefault(const char* key, const char* value);
    bool setBoolDefault(const char* key, bool value);

    // JsonProperties functions
    size_t size();

    bool reset(size_t index);
    bool reset(const char* key);
    bool reset();

    const char* keyOf(size_t index);
    int indexOf(const char* key);
  
    PropertyType typeOf(const char* key);
    PropertyType typeOf(size_t index);

    bool contains(const char* key);

    bool remove(size_t index);
    bool remove(const char* key);
    bool clear();

    bool serialize(char* json, size_t size);
    bool deserialize(const char* json);
};

#endif