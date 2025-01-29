# JsonProperties Library

The JsonProperties library is a simple and efficient library for managing properties in JSON format. It is particularly useful for transferring data over the network or storing data in a file. Each property is validated against a set of rules (min, max, etc.). So you can be sure that the data is always in a valid state.

## Features

- Manage properties in JSON format
- Validate properties against rules (min, max, etc.)
- Support for various property types: INT, LONG, FLOAT, DOUBLE, STRING, COLOR, BOOL, NONE
- Easy initialization and retrieval of properties
- Serialization and deserialization of properties

## Installation

To use the JsonProperties library, include the header file in your project:

```cpp
#include <JsonProperties.h>
```

## Usage

### Initialization

Create an instance of the JsonProperties class:

```cpp
JsonProperties jsonProps;
```

### Adding Properties

Initialize properties with default values and optional bounds:

```cpp
jsonProps.initInt("testInt", 10);
jsonProps.initInt("testIntBounds", 5, 0, 10);
jsonProps.initLong("testLong", 100L);
jsonProps.initLong("testLongBounds", 50L, 0L, 100L);
jsonProps.initFloat("testFloat", 1.23f);
jsonProps.initFloat("testFloatBounds", 1.23f, 0.0f, 10.0f);
jsonProps.initDouble("testDouble", 1.234);
jsonProps.initDouble("testDoubleBounds", 1.234, 0.0, 10.0);
jsonProps.initString("testString", "default");
jsonProps.initColor("testColor", "#FFFFFF");
jsonProps.initBool("testBool", true);
```

### Retrieving Properties

Retrieve the value of a property:

```cpp
int intValue = jsonProps.getInt("testInt");
long longValue = jsonProps.getLong("testLong");
float floatValue = jsonProps.getFloat("testFloat");
double doubleValue = jsonProps.getDouble("testDouble");
const char* stringValue = jsonProps.getString("testString");
const char* colorValue = jsonProps.getColor("testColor");
bool boolValue = jsonProps.getBool("testBool");
```

### Setting Properties

Set the value of a property:

```cpp
jsonProps.setInt("testInt", 20);
jsonProps.setLong("testLong", 200L);
jsonProps.setFloat("testFloat", 2.34f);
jsonProps.setDouble("testDouble", 2.345);
jsonProps.setString("testString", "newValue");
jsonProps.setColor("testColor", "#000000");
jsonProps.setBool("testBool", false);
```

### Serialization and Deserialization

Serialize properties to JSON:

```cpp
char json[256];
jsonProps.serialize(json, sizeof(json));
```

Deserialize properties from JSON:

```cpp
const char* json = "{\"testInt\":10,\"testString\":\"default\"}";
jsonProps.deserialize(json);
```
