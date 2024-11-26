/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
Node* copyRandomList(Node* head) {
    if (!head) return nullptr;

    // Step 1: Clone nodes and interweave them with the original list
    Node* current = head;
    while (current) {
        Node* copy = new Node(current->val);
        copy->next = current->next;
        current->next = copy;
        current = copy->next;
    }

    // Step 2: Set random pointers for the copied nodes
    current = head;
    while (current) {
        if (current->random) {
            current->next->random = current->random->next;
        }
        current = current->next->next; // Move to the next original node
    }

    // Step 3: Separate the copied list from the original list
    Node* dummyHead = new Node(0);
    Node* copyCurrent = dummyHead;
    current = head;
    while (current) {
        copyCurrent->next = current->next; // Link the copied node
        current->next = current->next->next; // Restore the original list
        
        current = current->next; // Move to the next original node
        copyCurrent = copyCurrent->next; // Move to the next copied node
    }

    return dummyHead->next;
}
};