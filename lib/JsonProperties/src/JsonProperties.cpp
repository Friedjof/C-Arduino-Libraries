#include "JsonProperties.h"

/**
 * @brief Construct a new Json Properties object.
 * 
 * This function constructs a new Json Properties object.
 */
JsonProperties::JsonProperties() {
}

/**
 * +--------------------------------------------------------------------------+
 * |                                                                          |
 * |  Initialize Functions                                                    |
 * |                                                                          |
 * +--------------------------------------------------------------------------+
 */

/**
 * @brief Initialize a property with a specific type.
 * 
 * This function initializes a property with a specific type.
 * If the property is already initialized or the type is invalid (color, min, max, etc.), the function returns false.
 * Default values:
 * - INT: 0
 * - LONG: 0
 * - FLOAT: 0.0
 * - DOUBLE: 0.0
 * - STRING: ""
 * - COLOR: "#000000"
 * - BOOL: false
 * 
 * @param key The key of the property.
 * @param type The type of the property.
 * @return true If the property was successfully initialized.
 */
bool JsonProperties::init(const char* key, PropertyType type) {
  if (this->contains(key)) {
    return false;
  }

  switch (type) {
    case PropertyType::INT:
      return this->initInt(key, 0);
    case PropertyType::LONG:
      return this->initLong(key, 0);
    case PropertyType::FLOAT:
      return this->initFloat(key, 0.0);
    case PropertyType::DOUBLE:
      return this->initDouble(key, 0.0);
    case PropertyType::STRING:
      return this->initString(key, "");
    case PropertyType::COLOR:
      return this->initColor(key, "#000000");
    case PropertyType::BOOL:
      return this->initBool(key, false);
    default:
      break;
  }
  
  return false;
}

/**
 * @brief Initialize an integer property.
 * 
 * This function initializes an integer property with a default value.
 * If the property is already initialized or the min/max values are invalid, the function returns false.
 * 
 * @param key The key of the property.
 * @param defaultValue The default value of the property.
 * @param min The minimum value of the property (default: INT_MIN).
 * @param max The maximum value of the property (default: INT_MAX).
 * @return true If the property was successfully initialized.
 */
bool JsonProperties::initInt(const char* key, int defaultValue, int min, int max) {
  if (this->contains(key) || min > max || defaultValue < min || defaultValue > max) {
    return false;
  }

  this->properties[key] = defaultValue;
  this->meta[key]["type"] = PropertyType::INT;
  this->meta[key]["min"] = min;
  this->meta[key]["max"] = max;
  keys.add(key);

  return this->contains(key);
}

/**
 * @brief Initialize an integer property.
 * 
 * This function initializes an integer property with a default value.
 * If the property is already initialized or the min/max values are invalid, the function returns false.
 * 
 * @param key The key of the property.
 * @param defaultValue The default value of the property.
 * @return true If the property was successfully initialized.
 */
bool JsonProperties::initInt(const char* key, int defaultValue) {
  return this->initInt(key, defaultValue, INT_MIN, INT_MAX);
}

/**
 * @brief Initialize a integer property.
 * 
 * This function initializes a integer property with min and max values.
 * The min value will be the default value.
 * 
 * @param key The key of the property.
 * @param min The minimum value of the property.
 * @param max The maximum value of the property.
 */
bool JsonProperties::initInt(const char* key, int min, int max) {
  return this->initInt(key, min, min, max);
}

/**
 * @brief Initialize a long property.
 * 
 * This function initializes a long property with a default value.
 * If the property is already initialized or the min/max values are invalid, the function returns false.
 * 
 * @param key The key of the property.
 * @param defaultValue The default value of the property.
 * @param min The minimum value of the property (default: LONG_MIN).
 * @param max The maximum value of the property (default: LONG_MAX).
 * @return true If the property was successfully initialized.
 */
bool JsonProperties::initLong(const char* key, long defaultValue, long min, long max) {
  if (this->contains(key) || min > max || defaultValue < min || defaultValue > max) {
    return false;
  }

  this->properties[key] = defaultValue;
  this->meta[key]["type"] = PropertyType::LONG;
  this->meta[key]["min"] = min;
  this->meta[key]["max"] = max;
  keys.add(key);

  return this->contains(key);
}

/**
 * @brief Initialize a long property.
 * 
 * This function initializes a long property with a default value.
 * If the property is already initialized or the min/max values are invalid, the function returns false.
 * 
 * @param key The key of the property.
 * @param defaultValue The default value of the property.
 */
bool JsonProperties::initLong(const char* key, long defaultValue) {
  return this->initLong(key, defaultValue, LONG_MIN, LONG_MAX);
}

/**
 * @brief Initialize a long property.
 * 
 * This function initializes a long property with a default value.
 * The min value will be the default value.
 * 
 * @param key The key of the property.
 * @param min The minimum value of the property (default: LONG_MIN).
 * @param max The maximum value of the property (default: LONG_MAX).
 * @return true If the property was successfully initialized.
 */
bool JsonProperties::initLong(const char* key, long min, long max) {
  return this->initLong(key, min, min, max);
}

/**
 * @brief Initialize a float property.
 * 
 * This function initializes a float property with a default value.
 * If the property is already initialized or the min/max values are invalid, the function returns false.
 * 
 * @param key The key of the property.
 * @param defaultValue The default value of the property.
 * @param min The minimum value of the property (default: -FLT_MAX).
 * @param max The maximum value of the property (default: FLT_MAX).
 * @return true If the property was successfully initialized.
 */
bool JsonProperties::initFloat(const char* key, float defaultValue, float min, float max) {
  if (this->contains(key) || min > max || defaultValue < min || defaultValue > max) {
    return false;
  }

  this->properties[key] = defaultValue;
  this->meta[key]["type"] = PropertyType::FLOAT;
  this->meta[key]["min"] = min;
  this->meta[key]["max"] = max;
  keys.add(key);

  return this->contains(key);
}

/**
 * @brief Initialize a float property.
 * 
 * This function initializes a float property with a default value.
 * If the property is already initialized or the min/max values are invalid, the function returns false.
 * 
 * @param key The key of the property.
 * @param defaultValue The default value of the property.
 * @return true If the property was successfully initialized.
 */
bool JsonProperties::initFloat(const char* key, float defaultValue) {
  return this->initFloat(key, defaultValue, __FLT_MIN__, __FLT_MAX__);
}

/**
 * @brief Initialize a float property.
 * 
 * This function initializes a double property with a default value.
 * The min value will be the default value.
 * 
 * @param key The key of the property.
 * @param min The minimum value of the property (default: -DBL_MAX).
 * @param max The maximum value of the property (default: DBL_MAX).
 * @return true If the property was successfully initialized.
 */
bool JsonProperties::initFloat(const char* key, float min, float max) {
  return this->initDouble(key, min, min, max);
}

/**
 * @brief Initialize a double property.
 * 
 * This function initializes a double property with a default value.
 * If the property is already initialized or the min/max values are invalid, the function returns false.
 * 
 * @param key The key of the property.
 * @param defaultValue The default value of the property.
 * @param min The minimum value of the property (default: -DBL_MAX).
 * @param max The maximum value of the property (default: DBL_MAX).
 * @return true If the property was successfully initialized.
 */
bool JsonProperties::initDouble(const char* key, double defaultValue, double min, double max) {
  if (this->contains(key) || min > max || defaultValue < min || defaultValue > max) {
    return false;
  }

  this->properties[key] = defaultValue;
  this->meta[key]["type"] = PropertyType::DOUBLE;
  this->meta[key]["min"] = min;
  this->meta[key]["max"] = max;
  keys.add(key);

  return this->contains(key);
}

/**
 * @brief Initialize a double property.
 * 
 * This function initializes a double property with a default value.
 * If the property is already initialized or the min/max values are invalid, the function returns false.
 * 
 * @param key The key of the property.
 * @param defaultValue The default value of the property.
 * @return true If the property was successfully initialized.
 */
bool JsonProperties::initDouble(const char* key, double defaultValue) {
  return this->initDouble(key, defaultValue, __DBL_MIN__, __DBL_MAX__);
}


/**
 * @brief Initialize a double property.
 * 
 * This function initializes a double property with a default value.
 * The min value will be the default value.
 * 
 * @param key The key of the property.
 * @param min The minimum value of the property (default: -DBL_MAX).
 * @param max The maximum value of the property (default: DBL_MAX).
 * @return true If the property was successfully initialized.
 */
bool JsonProperties::initDouble(const char* key, double min, double max) {
  return this->initDouble(key, min, min, max);
}

/**
 * @brief Initialize a string property.
 * 
 * This function initializes a string property with a default value.
 * If the property is already initialized, the function returns false.
 * 
 * @param key The key of the property.
 * @param defaultValue The default value of the property.
 */
bool JsonProperties::initString(const char* key, const char* defaultValue) {
  if (this->contains(key)) {
    return false;
  }

  this->properties[key] = defaultValue;
  this->meta[key]["type"] = PropertyType::STRING;
  keys.add(key);

  return this->contains(key);
}

/**
 * @brief Initialize a color property.
 * 
 * This function initializes a color property with a default value.
 * If the property is already initialized or the color is invalid, the function returns false.
 * 
 * @param key The key of the property.
 * @param defaultValue The default value of the property.
 */
bool JsonProperties::initColor(const char* key, const char* defaultValue) {
  if (this->contains(key) || !this->isColor(defaultValue)) {
    return false;
  }

  this->properties[key] = defaultValue;
  this->meta[key]["type"] = PropertyType::COLOR;
  keys.add(key);

  return this->contains(key);
}

/**
 * @brief Initialize a boolean property.
 * 
 * This function initializes a boolean property with a default value.
 * If the property is already initialized, the function returns false.
 * 
 * @param key The key of the property.
 * @param defaultValue The default value of the property.
 */
bool JsonProperties::initBool(const char* key, bool defaultValue) {
  if (this->contains(key)) {
    return false;
  }

  this->properties[key] = defaultValue;
  this->meta[key]["type"] = PropertyType::BOOL;
  keys.add(key);

  return this->contains(key);
}

/**
 * +--------------------------------------------------------------------------+
 * |                                                                          |
 * |  Get Value Functions                                                     |
 * |                                                                          |
 * +--------------------------------------------------------------------------+
 */

/**
 * @brief Get the value of an integer property.
 * 
 * This function returns the value of an integer property.
 * 
 * @param key The key of the property.
 * @return int The value of the property.
 */
int JsonProperties::getInt(const char* key) {
  return this->properties[key];
}

/**
 * @brief Get the value of a long property.
 * 
 * This function returns the value of a long property.
 * 
 * @param key The key of the property.
 * @return long The value of the property.
 */
long JsonProperties::getLong(const char* key) {
  return this->properties[key];
}

/**
 * @brief Get the value of a float property.
 * 
 * This function returns the value of a float property.
 * 
 * @param key The key of the property.
 * @return float The value of the property.
 */
float JsonProperties::getFloat(const char* key) {
  return this->properties[key];
}

/**
 * @brief Get the value of a double property.
 * 
 * This function returns the value of a double property.
 * 
 * @param key The key of the property.
 * @return double The value of the property.
 */
double JsonProperties::getDouble(const char* key) {
  return this->properties[key];
}

/**
 * @brief Get the value of a string property.
 * 
 * This function returns the value of a string property.
 * 
 * @param key The key of the property.
 * @return const char* The value of the property.
 */
const char* JsonProperties::getString(const char* key) {
  return this->properties[key];
}

/**
 * @brief Get the value of a color property.
 * 
 * This function returns the value of a color property.
 * 
 * @param key The key of the property.
 * @return const char* The value of the property.
 */
const char* JsonProperties::getColor(const char* key) {
  return this->properties[key];
}

/**
 * @brief Get the value of a boolean property.
 * 
 * This function returns the value of a boolean property.
 * 
 * @param key The key of the property.
 * @return bool The value of the property.
 */
bool JsonProperties::getBool(const char* key) {
  return this->properties[key];
}

/**
 * +--------------------------------------------------------------------------+
 * |                                                                          |
 * |  Set Value Functions                                                     |
 * |                                                                          |
 * +--------------------------------------------------------------------------+
 */

/**
 * @brief Set the value of an integer property.
 * 
 * This function sets the value of an integer property. The value has to be initialized and within the min/max bounds.
 * If the property does not exist or the value is out of bounds, the function returns false.
 * 
 * @param key The key of the property.
 * @param value The value of the property.
 * @return true If the value was successfully set.
 */
bool JsonProperties::setInt(const char* key, int value) {
  if (!this->contains(key) || this->typeOf(key) != PropertyType::INT || value < this->getIntMin(key) || value > this->getIntMax(key)) {
    return false;
  }

  this->properties[key] = value;
  return this->properties[key] == value;
}

/**
 * @brief Set the value of a long property.
 * 
 * This function sets the value of a long property. The value has to be initialized and within the min/max bounds.
 * If the property does not exist or the value is out of bounds, the function returns false.
 * 
 * @param key The key of the property.
 * @param value The value of the property.
 * @return true If the value was successfully set.
 */
bool JsonProperties::setLong(const char* key, long value) {
  if (!this->contains(key) || this->typeOf(key) != PropertyType::LONG || value < this->getLongMin(key) || value > this->getLongMax(key)) {
    return false;
  }

  this->properties[key] = value;
  return this->properties[key] == value;
}

/**
 * @brief Set the value of a float property.
 * 
 * This function sets the value of a float property. The value has to be initialized and within the min/max bounds.
 * If the property does not exist or the value is out of bounds, the function returns false.
 * 
 * @param key The key of the property.
 * @param value The value of the property.
 * @return true If the value was successfully set.
 */
bool JsonProperties::setFloat(const char* key, float value) {
  if (!this->contains(key) || this->typeOf(key) != PropertyType::FLOAT || value < this->getFloatMin(key) || value > this->getFloatMax(key)) {
    return false;
  }

  this->properties[key] = value;
  return this->properties[key] == value;
}

/**
 * @brief Set the value of a double property.
 * 
 * This function sets the value of a double property. The value has to be initialized and within the min/max bounds.
 * If the property does not exist or the value is out of bounds, the function returns false.
 * 
 * @param key The key of the property.
 * @param value The value of the property.
 * @return true If the value was successfully set.
 */
bool JsonProperties::setDouble(const char* key, double value) {
  if (!this->contains(key) || this->typeOf(key) != PropertyType::DOUBLE || value < this->getDoubleMin(key) || value > this->getDoubleMax(key)) {
    return false;
  }

  this->properties[key] = value;
  return this->properties[key] == value;
}

/**
 * @brief Set the value of a string property.
 * 
 * This function sets the value of a string property. The value has to be initialized.
 * If the property does not exist, the function returns false.
 * 
 * @param key The key of the property.
 * @param value The value of the property.
 * @return true If the value was successfully set.
 */
bool JsonProperties::setString(const char* key, const char* value) {
  if (!this->contains(key) || this->typeOf(key) != PropertyType::STRING) {
    return false;
  }

  this->properties[key] = value;
  return this->properties[key] == value;
}

/**
 * @brief Set the value of a color property.
 * 
 * This function sets the value of a color property. The value has to be initialized and valid.
 * If the property does not exist or the color is invalid, the function returns false.
 * 
 * @param key The key of the property.
 * @param value The value of the property.
 * @return true If the value was successfully set.
 */
bool JsonProperties::setColor(const char* key, const char* value) {
  if (!this->contains(key) || this->typeOf(key) != PropertyType::COLOR || !this->isColor(value)) {
    return false;
  }

  this->properties[key] = value;
  return this->properties[key] == value;
}

/**
 * @brief Set the value of a boolean property.
 * 
 * This function sets the value of a boolean property. The value has to be initialized.
 * If the property does not exist, the function returns false.
 * 
 * @param key The key of the property.
 * @param value The value of the property.
 * @return true If the value was successfully set.
 */
bool JsonProperties::setBool(const char* key, bool value) {
  if (!this->contains(key) || this->typeOf(key) != PropertyType::BOOL) {
    return false;
  }

  this->properties[key] = value;
  return true;
}

/**
 * +--------------------------------------------------------------------------+
 * |                                                                          |
 * |  Get Bounds Functions                                                    |
 * |                                                                          |
 * +--------------------------------------------------------------------------+
 */

/**
 * @brief Get the minimum value of an integer property.
 * 
 * This function returns the minimum value of an integer property.
 * If the property does not exist or the type is invalid, the function returns INT_MIN.
 * 
 * @param key The key of the property.
 * @return int The minimum value of the property.
 */
int JsonProperties::getIntMin(const char* key) {
  if (!this->contains(key) || this->typeOf(key) != PropertyType::INT) {
    return INT_MIN;
  }

  return this->meta[key]["min"];
}

/**
 * @brief Get the maximum value of an integer property.
 * 
 * This function returns the maximum value of an integer property.
 * If the property does not exist or the type is invalid, the function returns INT_MAX.
 * 
 * @param key The key of the property.
 * @return int The maximum value of the property.
 */
int JsonProperties::getIntMax(const char* key) {
  if (!this->contains(key) || this->typeOf(key) != PropertyType::INT) {
    return INT_MAX;
  }

  return this->meta[key]["max"];
}

/**
 * @brief Get the minimum value of a long property.
 * 
 * This function returns the minimum value of a long property.
 * If the property does not exist or the type is invalid, the function returns LONG_MIN.
 * 
 * @param key The key of the property.
 * @return long The minimum value of the property.
 */
long JsonProperties::getLongMin(const char* key) {
  if (!this->contains(key) || this->typeOf(key) != PropertyType::LONG) {
    return LONG_MIN;
  }

  return this->meta[key]["min"];
}

/**
 * @brief Get the maximum value of a long property.
 * 
 * This function returns the maximum value of a long property.
 * If the property does not exist or the type is invalid, the function returns LONG_MAX.
 * 
 * @param key The key of the property.
 * @return long The maximum value of the property.
 */

long JsonProperties::getLongMax(const char* key) {
  if (!this->contains(key) || this->typeOf(key) != PropertyType::LONG) {
    return LONG_MAX;
  }

  return this->meta[key]["max"];
}

/**
 * @brief Get the minimum value of a float property.
 * 
 * This function returns the minimum value of a float property.
 * If the property does not exist or the type is invalid, the function returns -FLT_MAX.
 * 
 * @param key The key of the property.
 * @return float The minimum value of the property.
 */
float JsonProperties::getFloatMin(const char* key) {
  if (!this->contains(key) || this->typeOf(key) != PropertyType::FLOAT) {
    return -__FLT_MAX__;
  }

  return this->meta[key]["min"];
}

/**
 * @brief Get the maximum value of a float property.
 * 
 * This function returns the maximum value of a float property.
 * If the property does not exist or the type is invalid, the function returns FLT_MAX.
 * 
 * @param key The key of the property.
 * @return float The maximum value of the property.
 */
float JsonProperties::getFloatMax(const char* key) {
  if (!this->contains(key) || this->typeOf(key) != PropertyType::FLOAT) {
    return __FLT_MAX__;
  }

  return this->meta[key]["max"];
}

/**
 * @brief Get the minimum value of a double property.
 * 
 * This function returns the minimum value of a double property.
 * If the property does not exist or the type is invalid, the function returns -DBL_MAX.
 * 
 * @param key The key of the property.
 * @return double The minimum value of the property.
 */
double JsonProperties::getDoubleMin(const char* key) {
  if (!this->contains(key) || this->typeOf(key) != PropertyType::DOUBLE) {
    return -__DBL_MAX__;
  }

  return this->meta[key]["min"];
}

/**
 * @brief Get the maximum value of a double property.
 * 
 * This function returns the maximum value of a double property.
 * If the property does not exist or the type is invalid, the function returns DBL_MAX.
 * 
 * @param key The key of the property.
 * @return double The maximum value of the property.
 */
double JsonProperties::getDoubleMax(const char* key) {
  if (!this->contains(key) || this->typeOf(key) != PropertyType::DOUBLE) {
    return __DBL_MAX__;
  }

  return this->meta[key]["max"];
}

/**
 * +--------------------------------------------------------------------------+
 * |                                                                          |
 * |  Set Bounds Functions                                                    |
 * |                                                                          |
 * +--------------------------------------------------------------------------+
 */

/**
 * @brief Set the bounds of an integer property.
 * 
 * This function sets the bounds of an integer property (min has to be less than max).
 * If the property does not exist or the type is invalid, the function returns false.
 * 
 * @param key The key of the property.
 * @param min The minimum value of the property.
 * @param max The maximum value of the property.
 * @return true If the bounds were successfully set.
 */
bool JsonProperties::setIntBounds(const char* key, int min, int max) {
  if (!this->contains(key) || this->typeOf(key) != PropertyType::INT || min > max) {
    return false;
  }

  this->meta[key]["min"] = min;
  this->meta[key]["max"] = max;
  return this->getIntMin(key) == min && this->getIntMax(key) == max;
}

/**
 * @brief Set the minimum value of an integer property.
 * 
 * This function sets the minimum value of an integer property (min has to be less than max).
 * If the property does not exist or the type is invalid, the function returns false.
 * 
 * @param key The key of the property.
 * @param min The minimum value of the property.
 * @return true If the minimum value was successfully set.
 */
bool JsonProperties::setIntMin(const char* key, int min) {
  if (!this->contains(key) || this->typeOf(key) != PropertyType::INT || min > this->getIntMax(key)) {
    return false;
  }

  this->meta[key]["min"] = min;
  return this->getIntMin(key) == min;
}

/**
 * @brief Set the bounds of a long property.
 * 
 * This function sets the bounds of a long property (min has to be less than max).
 * If the property does not exist or the type is invalid, the function returns false.
 * 
 * @param key The key of the property.
 * @param min The minimum value of the property.
 * @param max The maximum value of the property.
 * @return true If the bounds were successfully set.
 */
bool JsonProperties::setLongBounds(const char* key, long min, long max) {
  if (!this->contains(key) || this->typeOf(key) != PropertyType::LONG || min > max) {
    return false;
  }

  this->meta[key]["min"] = min;
  this->meta[key]["max"] = max;
  return this->getLongMin(key) == min && this->getLongMax(key) == max;
}

/**
 * @brief Set the minimum value of a long property.
 * 
 * This function sets the minimum value of a long property (min has to be less than max).
 * If the property does not exist or the type is invalid, the function returns false.
 * 
 * @param key The key of the property.
 * @param min The minimum value of the property.
 * @return true If the minimum value was successfully set.
 */
bool JsonProperties::setLongMin(const char* key, long min) {
  if (!this->contains(key) || this->typeOf(key) != PropertyType::LONG || min > this->getLongMax(key)) {
    return false;
  }

  this->meta[key]["min"] = min;
  return this->getLongMin(key) == min;
}

/**
 * @brief Set the bounds of a float property.
 * 
 * This function sets the bounds of a float property (min has to be less than max).
 * If the property does not exist or the type is invalid, the function returns false.
 * 
 * @param key The key of the property.
 * @param min The minimum value of the property.
 * @param max The maximum value of the property.
 * @return true If the bounds were successfully set.
 */
bool JsonProperties::setFloatBounds(const char* key, float min, float max) {
  if (!this->contains(key) || this->typeOf(key) != PropertyType::FLOAT || min > max) {
    return false;
  }

  this->meta[key]["min"] = min;
  this->meta[key]["max"] = max;
  return this->getFloatMin(key) == min && this->getFloatMax(key) == max;
}

/**
 * @brief Set the minimum value of a float property.
 * 
 * This function sets the minimum value of a float property (min has to be less than max).
 * If the property does not exist or the type is invalid, the function returns false.
 * 
 * @param key The key of the property.
 * @param min The minimum value of the property.
 * @return true If the minimum value was successfully set.
 */
bool JsonProperties::setFloatMin(const char* key, float min) {
  if (!this->contains(key) || this->typeOf(key) != PropertyType::FLOAT || min > this->getFloatMax(key)) {
    return false;
  }

  this->meta[key]["min"] = min;
  return this->getFloatMin(key) == min;
}

/**
 * @brief Set the bounds of a double property.
 * 
 * This function sets the bounds of a double property (min has to be less than max).
 * If the property does not exist or the type is invalid, the function returns false.
 * 
 * @param key The key of the property.
 * @param min The minimum value of the property.
 * @param max The maximum value of the property.
 * @return true If the bounds were successfully set.
 */
bool JsonProperties::setDoubleBounds(const char* key, double min, double max) {
  if (!this->contains(key) || this->typeOf(key) != PropertyType::DOUBLE || min > max) {
    return false;
  }

  this->meta[key]["min"] = min;
  this->meta[key]["max"] = max;
  return this->getDoubleMin(key) == min && this->getDoubleMax(key) == max;
}

/**
 * @brief Set the minimum value of a double property.
 * 
 * This function sets the minimum value of a double property (min has to be less than max).
 * If the property does not exist or the type is invalid, the function returns false.
 * 
 * @param key The key of the property.
 * @param min The minimum value of the property.
 * @return true If the minimum value was successfully set.
 */
bool JsonProperties::setDoubleMin(const char* key, double min) {
  if (!this->contains(key) || this->typeOf(key) != PropertyType::DOUBLE || min > this->getDoubleMax(key)) {
    return false;
  }

  this->meta[key]["min"] = min;
  return this->getDoubleMin(key) == min;
}

/**
 * +--------------------------------------------------------------------------+
 * |                                                                          |
 * |  Get Default Functions                                                   |
 * |                                                                          |
 * +--------------------------------------------------------------------------+
 */

/**
 * @brief Get the default value of an integer property.
 * 
 * This function returns the default value of an integer property.
 * If the property does not exist or the type is invalid, the function returns 0.
 * 
 * @param key The key of the property.
 * @return int The default value of the property.
 */
int JsonProperties::getIntDefault(const char* key) {
  if (!this->contains(key) || this->typeOf(key) != PropertyType::INT) {
    return 0;
  }

  return this->meta[key]["default"];
}

/**
 * @brief Get the default value of a long property.
 * 
 * This function returns the default value of a long property.
 * If the property does not exist or the type is invalid, the function returns 0.
 * 
 * @param key The key of the property.
 * @return long The default value of the property.
 */
long JsonProperties::getLongDefault(const char* key) {
  if (!this->contains(key) || this->typeOf(key) != PropertyType::LONG) {
    return 0;
  }

  return this->meta[key]["default"];
}

/**
 * @brief Get the default value of a float property.
 * 
 * This function returns the default value of a float property.
 * If the property does not exist or the type is invalid, the function returns 0.0.
 * 
 * @param key The key of the property.
 * @return float The default value of the property.
 */
float JsonProperties::getFloatDefault(const char* key) {
  if (!this->contains(key) || this->typeOf(key) != PropertyType::FLOAT) {
    return 0.0;
  }

  return this->meta[key]["default"];
}

/**
 * @brief Get the default value of a double property.
 * 
 * This function returns the default value of a double property.
 * If the property does not exist or the type is invalid, the function returns 0.0.
 * 
 * @param key The key of the property.
 * @return double The default value of the property.
 */
double JsonProperties::getDoubleDefault(const char* key) {
  if (!this->contains(key) || this->typeOf(key) != PropertyType::DOUBLE) {
    return 0.0;
  }

  return this->meta[key]["default"];
}

/**
 * @brief Get the default value of a string property.
 * 
 * This function returns the default value of a string property.
 * If the property does not exist or the type is invalid, the function returns "".
 * 
 * @param key The key of the property.
 * @return const char* The default value of the property.
 */
const char* JsonProperties::getStringDefault(const char* key) {
  if (!this->contains(key) || this->typeOf(key) != PropertyType::STRING) {
    return "";
  }

  return this->meta[key]["default"];
}

/**
 * @brief Get the default value of a color property.
 * 
 * This function returns the default value of a color property.
 * If the property does not exist or the type is invalid, the function returns "#000000".
 * 
 * @param key The key of the property.
 * @return const char* The default value of the property.
 */
const char* JsonProperties::getColorDefault(const char* key) {
  if (!this->contains(key) || this->typeOf(key) != PropertyType::COLOR) {
    return "#000000";
  }

  return this->meta[key]["default"];
}

/**
 * @brief Get the default value of a boolean property.
 * 
 * This function returns the default value of a boolean property.
 * If the property does not exist or the type is invalid, the function returns false.
 * 
 * @param key The key of the property.
 * @return bool The default value of the property.
 */
bool JsonProperties::getBoolDefault(const char* key) {
  if (!this->contains(key) || this->typeOf(key) != PropertyType::BOOL) {
    return false;
  }

  return this->meta[key]["default"];
}

/**
 * +--------------------------------------------------------------------------+
 * |                                                                          |
 * |  Set Default Functions                                                   |
 * |                                                                          |
 * +--------------------------------------------------------------------------+
 */

/**
 * @brief Set the default value of an integer property.
 * 
 * This function sets the default value of an integer property.
 * If the property does not exist, the type is invalid, or the default value is out of bounds, the function returns false.
 * 
 * @param key The key of the property.
 * @param defaultValue The default value of the property.
 * @return true If the default value was successfully set.
 */
bool JsonProperties::setIntDefault(const char* key, int defaultValue) {
  if (!this->contains(key) || this->typeOf(key) != PropertyType::INT || defaultValue < this->getIntMin(key) || defaultValue > this->getIntMax(key)) {
    return false;
  }

  this->meta[key]["default"] = defaultValue;
  return this->getIntDefault(key) == defaultValue;
}

/**
 * @brief Set the default value of a long property.
 * 
 * This function sets the default value of a long property.
 * If the property does not exist, the type is invalid, or the default value is out of bounds, the function returns false.
 * 
 * @param key The key of the property.
 * @param defaultValue The default value of the property.
 * @return true If the default value was successfully set.
 */
bool JsonProperties::setLongDefault(const char* key, long defaultValue) {
  if (!this->contains(key) || this->typeOf(key) != PropertyType::LONG || defaultValue < this->getLongMin(key) || defaultValue > this->getLongMax(key)) {
    return false;
  }

  this->meta[key]["default"] = defaultValue;
  return this->getLongDefault(key) == defaultValue;
}

/**
 * @brief Set the default value of a float property.
 * 
 * This function sets the default value of a float property.
 * If the property does not exist, the type is invalid, or the default value is out of bounds, the function returns false.
 * 
 * @param key The key of the property.
 * @param defaultValue The default value of the property.
 * @return true If the default value was successfully set.
 */
bool JsonProperties::setFloatDefault(const char* key, float defaultValue) {
  if (!this->contains(key) || this->typeOf(key) != PropertyType::FLOAT || defaultValue < this->getFloatMin(key) || defaultValue > this->getFloatMax(key)) {
    return false;
  }

  this->meta[key]["default"] = defaultValue;
  return this->getFloatDefault(key) == defaultValue;
}

/**
 * @brief Set the default value of a double property.
 * 
 * This function sets the default value of a double property.
 * If the property does not exist, the type is invalid, or the default value is out of bounds, the function returns false.
 * 
 * @param key The key of the property.
 * @param defaultValue The default value of the property.
 * @return true If the default value was successfully set.
 */
bool JsonProperties::setDoubleDefault(const char* key, double defaultValue) {
  if (!this->contains(key) || this->typeOf(key) != PropertyType::DOUBLE || defaultValue < this->getDoubleMin(key) || defaultValue > this->getDoubleMax(key)) {
    return false;
  }

  this->meta[key]["default"] = defaultValue;
  return this->getDoubleDefault(key) == defaultValue;
}

/**
 * @brief Set the default value of a string property.
 * 
 * This function sets the default value of a string property.
 * If the property does not exist or the type is invalid, the function returns false.
 * 
 * @param key The key of the property.
 * @param defaultValue The default value of the property.
 * @return true If the default value was successfully set.
 */
bool JsonProperties::setStringDefault(const char* key, const char* defaultValue) {
  if (!this->contains(key) || this->typeOf(key) != PropertyType::STRING) {
    return false;
  }

  this->meta[key]["default"] = defaultValue;
  return this->getStringDefault(key) == defaultValue;
}

/**
 * @brief Set the default value of a color property.
 * 
 * This function sets the default value of a color property.
 * If the property does not exist or the type is invalid, the function returns false.
 * 
 * @param key The key of the property.
 * @param defaultValue The default value of the property.
 * @return true If the default value was successfully set.
 */
bool JsonProperties::setColorDefault(const char* key, const char* defaultValue) {
  if (!this->contains(key) || this->typeOf(key) != PropertyType::COLOR || !this->isColor(defaultValue)) {
    return false;
  }

  this->meta[key]["default"] = defaultValue;
  return this->getColorDefault(key) == defaultValue;
}

/**
 * @brief Set the default value of a boolean property.
 * 
 * This function sets the default value of a boolean property.
 * If the property does not exist or the type is invalid, the function returns false.
 * 
 * @param key The key of the property.
 * @param defaultValue The default value of the property.
 * @return true If the default value was successfully set.
 */
bool JsonProperties::setBoolDefault(const char* key, bool defaultValue) {
  if (!this->contains(key) || this->typeOf(key) != PropertyType::BOOL) {
    return false;
  }

  this->meta[key]["default"] = defaultValue;
  return this->getBoolDefault(key) == defaultValue;
}

/**
 * +--------------------------------------------------------------------------+
 * |                                                                          |
 * |  JsonProperties Functions                                                |
 * |                                                                          |
 * +--------------------------------------------------------------------------+
 */

/**
 * @brief Get the number of properties.
 * 
 * This function returns the number of properties.
 * 
 * @return int The number of properties.
 */
size_t JsonProperties::size() {
  return this->getSize();
}

/**
 * @brief Reset value by index.
 * 
 * This function sets the value of a property to its default value.
 * If the index is out of bounds, the function returns false.
 * 
 * @param index The index of the property.
 * @return true If the value was successfully reset.
 */
bool JsonProperties::reset(size_t index) {
  if (index < 0 || index >= this->getSize()) {
    return false;
  }

  PropertyType type = this->typeOf(index);

  switch (type) {
    case PropertyType::INT:
      return this->setInt(this->keyOf(index), this->getIntDefault(this->keyOf(index)));
    case PropertyType::LONG:
      return this->setLong(this->keyOf(index), this->getLongDefault(this->keyOf(index)));
    case PropertyType::FLOAT:
      return this->setFloat(this->keyOf(index), this->getFloatDefault(this->keyOf(index)));
    case PropertyType::DOUBLE:
      return this->setDouble(this->keyOf(index), this->getDoubleDefault(this->keyOf(index)));
    case PropertyType::STRING:
      return this->setString(this->keyOf(index), this->getStringDefault(this->keyOf(index)));
    case PropertyType::COLOR:
      return this->setColor(this->keyOf(index), this->getColorDefault(this->keyOf(index)));
    case PropertyType::BOOL:
      return this->setBool(this->keyOf(index), this->getBoolDefault(this->keyOf(index)));
    default:
      break;
  }

  return false;
}

/**
 * @brief Reset value by key.
 * 
 * This function sets the value of a property to its default value.
 * If the property does not exist, the function returns false.
 * 
 * @param key The key of the property.
 * @return true If the value was successfully reset.
 */
bool JsonProperties::reset(const char* key) {
  return this->reset(this->indexOf(key));
}

/**
 * @brief Reset all properties.
 * 
 * This function sets the value of all properties to their default values.
 * 
 * @return true If all values were successfully reset.
 */
bool JsonProperties::reset() {
  bool result = true;

  for (size_t i = 0; i < this->getSize(); i++) {
    if (!this->reset(i)) result = false;
  }

  return result;
}

/**
 * @brief Get the key of a property by index.
 * 
 * This function returns the key of a property by index.
 * If the index is out of bounds, the function returns an empty string.
 * 
 * @param index The index of the property.
 * @return const char* The key of the property.
 */
const char* JsonProperties::keyOf(size_t index) {
  if (index < 0 || index >= this->getSize()) {
    return "";
  }

  return this->keys.get(index).c_str();
}

/**
 * @brief Get the index of a property by key.
 * 
 * This function returns the index of a property by key.
 * If the property does not exist, the function returns -1.
 * 
 * @param key The key of the property.
 * @return int The index of the property.
 */
int JsonProperties::indexOf(const char* key) {
  return this->keys.indexOf(key);
}

/**
 * @brief Get the type of a property by key.
 * 
 * This function returns the type of a property by key.
 * If the property does not exist, the function returns PropertyType::NONE.
 * 
 * @param key The key of the property.
 * @return PropertyType The type of the property.
 */
PropertyType JsonProperties::typeOf(const char* key) {
  if (!this->contains(key)) {
    return PropertyType::NONE;
  }

  return this->meta[key]["type"];
}

/**
 * @brief Get the type of a property by index.
 * 
 * This function returns the type of a property by index.
 * If the index is out of bounds, the function returns PropertyType::NONE.
 * 
 * @param index The index of the property.
 */
PropertyType JsonProperties::typeOf(size_t index) {
  if (index < 0 || index >= this->getSize()) {
    return PropertyType::NONE;
  }

  return this->typeOf(this->keys.get(index).c_str());
}

/**
 * @brief Check if a property exists.
 * 
 * This function checks if a property exists.
 * 
 * @param key The key of the property.
 * @return true If the property exists.
 */
bool JsonProperties::contains(const char* key) {
  return this->keys.contains(key);
}

/**
 * @brief Remove a property by index.
 * 
 * This function removes a property by index from the properties.
 * If the index is out of bounds, the function returns false.
 * 
 * @param index The index of the property.
 * @return true If the property was successfully removed.
 */
bool JsonProperties::remove(size_t index) {
  if (index < 0 || index >= this->getSize()) {
    return false;
  }

  return this->remove(this->keys.get(index).c_str());
}

/**
 * @brief Remove a property by key.
 * 
 * This function removes a property by key from the properties.
 * If the property does not exist, the function returns false.
 * 
 * @param key The key of the property.
 * @return true If the property was successfully removed.
 */
bool JsonProperties::remove(const char* key) {
  return this->remove(this->indexOf(key));
}

/**
 * @brief Remove all properties.
 * 
 * This function removes all properties from the properties.
 * 
 * @return true If all properties were successfully removed.
 */
bool JsonProperties::clear() {
  this->keys.clear();
  this->properties.clear();
  this->meta.clear();
  return this->getSize() == 0;
}

/**
 * @brief Get the JSON string of the properties.
 * 
 * This function returns the JSON string of the properties.
 * If the JSON string is too long, the function returns false.
 * 
 * @return const char* The JSON string of the properties.
 */
bool JsonProperties::serialize(char* json, size_t size) {
  String serialized;
  serializeJson(this->properties, serialized);

  if (serialized.length() >= size) {
    return false;
  }

  serialized.toCharArray(json, size);

  return serialized.length() < size;
}

/**
 * @brief Set the properties from a JSON string.
 * 
 * This function sets the properties from a JSON string.
 * If the JSON string is valid and every property is set successfully, the function returns true.
 * 
 * @param json The JSON string of the properties.
 * @return true If the every property was successfully set.
 */
bool JsonProperties::deserialize(const char* json) {
  JsonDocument doc;
  DeserializationError error = deserializeJson(doc, json);

  bool success = true;

  if (error) {
    return false;
  }

  for (unsigned int i = 0; i < this->getSize(); i++) {
    const char* key = this->keyOf(i);
    PropertyType type = this->typeOf(key);

    switch (type) {
      case PropertyType::INT:
        if (!doc[key].is<int>() || !this->setInt(key, doc[key])) success = false;
        break;
      case PropertyType::LONG:
        if (!doc[key].is<long>() || !this->setLong(key, doc[key])) success = false;
        break;
      case PropertyType::FLOAT:
        if (!doc[key].is<float>() || !this->setFloat(key, doc[key])) success = false;
        break;
      case PropertyType::DOUBLE:
        if (!doc[key].is<double>() || !this->setDouble(key, doc[key])) success = false;
        break;
      case PropertyType::STRING:
        if (!doc[key].is<const char*>() || !this->setString(key, doc[key])) success = false;
        break;
      case PropertyType::COLOR:
        if (!doc[key].is<const char*>() || !this->setColor(key, doc[key])) success = false;
        break;
      case PropertyType::BOOL:
        if (!doc[key].is<bool>() || !this->setBool(key, doc[key])) success = false;
        break;
      default:
        break;
    }
  }

  return success;
}

/**
 * +--------------------------------------------------------------------------+
 * |                                                                          |
 * |  Private Helper Functions                                                |
 * |                                                                          |
 * +--------------------------------------------------------------------------+
 */

/**
 * @brief Check if color is valid (hexadecimal).
 * 
 * This function checks if a color is valid (hexadecimal).
 * Examples for valid colors:
 * - #000000
 * - #FFFFFF
 * - #ff0000
 * - #00ff00
 * - #0000ff
 * 
 * Examples for invalid colors:
 * - #0000R0
 * - #0000
 * - #000
 * 
 * @param value The color value.
 * @return true If the color is valid.
 */
bool JsonProperties::isColor(const char* value) {
  return (strlen(value) == 7 && value[0] == '#' && strspn(value + 1, "0123456789abcdefABCDEF") == 6);
}

/**
 * @brief Get the number of properties.
 * 
 * This function returns the number of properties.
 * 
 * @return size_t The number of properties.
 */
size_t JsonProperties::getSize() {
  return this->properties.size();
}