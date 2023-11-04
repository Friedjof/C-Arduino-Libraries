#include <Arduino.h>
#include <Properties.h>
#include "MyDictionary.h"
#include "LinkedList.h"
#include "UnorderedMap.h"
#include "SDList.h"


Properties prop;
Hashtable<String, int> hashtable;
SimpleVector<String> keys = hashtable.keys();
// put function declarations here:
int myFunction(int, int);

void setup() {
  prop.loadFromSD("test.txt");
  prop.setProperty("test", "test");
  prop.saveToSD("test.txt");

  prop.setProperty("item1", "test2", "test.txt");
  hashtable.put("apple", 5);
  hashtable.put("banana", 3);
  hashtable.put("cherry", 8);
  
  int* applePointer = hashtable.get("apple");
  int appleCount = applePointer ? *applePointer : 0; // checks if applePointer is not null before dereferencing

  int* bananaPointer = hashtable.get("banana");
  int bananaCount = bananaPointer ? *bananaPointer : 0; // checks if bananaPointer is not null before dereferencing
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}