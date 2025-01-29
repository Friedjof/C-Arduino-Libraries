#ifndef TEST_INIT_H
#define TEST_INIT_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include <unity.h>

#include <JsonProperties.h>


JsonProperties jsonProps;

void setUp(void) {
  // Set up code here, to run before each test
  jsonProps = JsonProperties();
}

void tearDown(void) {
  // Clean up code here, to run after each test
}

void test_initInt(void) {
  bool result = jsonProps.initInt("testInt", 10);
  TEST_ASSERT_TRUE(result);
  TEST_ASSERT_EQUAL_INT(10, jsonProps.getInt("testInt"));
}

void test_initIntWithBounds(void) {
  bool result = jsonProps.initInt("testIntBounds", 5, 0, 10);
  TEST_ASSERT_TRUE(result);
  TEST_ASSERT_EQUAL_INT(5, jsonProps.getInt("testIntBounds"));
  TEST_ASSERT_EQUAL_INT(0, jsonProps.getIntMin("testIntBounds"));
  TEST_ASSERT_EQUAL_INT(10, jsonProps.getIntMax("testIntBounds"));
}

void test_initLong(void) {
  bool result = jsonProps.initLong("testLong", 100L);
  TEST_ASSERT_TRUE(result);
  TEST_ASSERT_EQUAL_INT32(100L, jsonProps.getLong("testLong"));
}

void test_initLongWithBounds(void) {
  bool result = jsonProps.initLong("testLongBounds", 50L, 0L, 100L);
  TEST_ASSERT_TRUE(result);
  TEST_ASSERT_EQUAL_INT32(50L, jsonProps.getLong("testLongBounds"));
  TEST_ASSERT_EQUAL_INT32(0L, jsonProps.getLongMin("testLongBounds"));
  TEST_ASSERT_EQUAL_INT32(100L, jsonProps.getLongMax("testLongBounds"));
}

void test_initFloat(void) {
  bool result = jsonProps.initFloat("testFloat", 1.23f);
  TEST_ASSERT_TRUE(result);
  TEST_ASSERT_EQUAL_FLOAT(1.23f, jsonProps.getFloat("testFloat"));
}

void test_initFloatWithBounds(void) {
  bool result = jsonProps.initFloat("testFloatBounds", 1.23f, 0.0f, 10.0f);
  TEST_ASSERT_TRUE(result);
  TEST_ASSERT_EQUAL_FLOAT(1.23f, jsonProps.getFloat("testFloatBounds"));
  TEST_ASSERT_EQUAL_FLOAT(0.0f, jsonProps.getFloatMin("testFloatBounds"));
  TEST_ASSERT_EQUAL_FLOAT(10.0f, jsonProps.getFloatMax("testFloatBounds"));
}

void test_initString(void) {
  bool result = jsonProps.initString("testString", "default");
  TEST_ASSERT_TRUE(result);
  TEST_ASSERT_EQUAL_STRING("default", jsonProps.getString("testString"));
}

void test_initColor(void) {
  bool result = jsonProps.initColor("testColor", "#FFFFFF");
  TEST_ASSERT_TRUE(result);
  TEST_ASSERT_EQUAL_STRING("#FFFFFF", jsonProps.getColor("testColor"));
}

void test_initBool(void) {
  bool result = jsonProps.initBool("testBool", true);
  TEST_ASSERT_TRUE(result);
  TEST_ASSERT_TRUE(jsonProps.getBool("testBool"));
}

void setup() {
  UNITY_BEGIN();
  RUN_TEST(test_initInt);
  RUN_TEST(test_initIntWithBounds);
  RUN_TEST(test_initLong);
  RUN_TEST(test_initLongWithBounds);
  RUN_TEST(test_initFloat);
  RUN_TEST(test_initFloatWithBounds);
  RUN_TEST(test_initString);
  RUN_TEST(test_initColor);
  RUN_TEST(test_initBool);
  UNITY_END();
}

void loop() {
  // Empty loop
}

#endif // TEST_INIT_H