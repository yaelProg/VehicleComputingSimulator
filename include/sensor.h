#ifndef __SENSOR_H__
#define __SENSOR_H__

#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <optional>
#include "basic_condition.h"
#include "enums.h"
using namespace std;

class Sensor {
public:
    int id;
    // Contains the current values of various fields and a list of basic conditions associated with each field
    map<string, pair<string, vector<BasicCondition *>>> fields;

    // C-tor initializes the id member variable.
    Sensor(int id) : id(id){};

    // Updates the condition status according to the received field and returns the  list of the full conditions whose root is true
    void updateTrueRoots(string field, string value);
    // Executes a specified action for the sensor.
    virtual void doAction(string action){};
};

#endif  // _SENSOR_H_