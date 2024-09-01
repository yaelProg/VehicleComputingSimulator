#include "operator_node.h"

// Function that updates the status of all nodes that should change
void OperatorNode::updateTree()
{
    bool prevStatus = this->status;

    // Update the status of the current node
    this->updateStatus();

    // TODO: Check what would happen if the root was true and we got to it with true

    // Check if the status changed
    if (prevStatus != this->status) {
        // Go over all the parents and update them
        for (Node *parent : this->parents) {
            (this->status) ? parent->countTrueConditions++
                           : parent->countTrueConditions--;
            parent->updateTree();
        }
    }
}