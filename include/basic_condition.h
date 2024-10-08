
#ifndef __BASIC_CONDITION_H__
#define __BASIC_CONDITION_H__

#include <map>
#include <string>
#include "operator_node.h"
#include "enums.h"

using namespace std;

// Class that present a leaf - basic condition
class BasicCondition : public Condition {
public:
    string value;
    OperatorTypes operatorType;
};

#endif  // _BASIC_CONDITION_H_