#include "test_helper.h"

// Tests a condition by resetting global state and updating sensor values
void testCondition(string condition, int sensorId, string field, string value)
{
    // Resets counters and existing conditions, recreates the `GlobalProperties` instance
    FullCondition::s_counter = 0;
    FullCondition::s_existingConditions = {};
    GlobalProperties::resetInstance();

    GlobalProperties &instanceGP = GlobalProperties::getInstance();

    // Creates a `FullCondition` object with the given parameters
    map<int, string> map = {{8, "the condition is true"}};
    FullCondition *cond = new FullCondition(condition, map);
    instanceGP.conditions[cond->id] = cond;

    // Updates a specified sensor with the provided field and value
    Sensor *sensor = instanceGP.sensors[sensorId];
    sensor->updateTrueRoots(field, value);
}