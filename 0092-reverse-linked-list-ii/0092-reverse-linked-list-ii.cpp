/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;

        stack<ListNode*> stc;
        int c = 1;

        // Create a dummy node to simplify edge cases
        ListNode* result = new ListNode(0);
        result->next = head;

        ListNode* temp = result;

        // Move temp to the node just before the 'left' position
        while (c < left) {
            temp = temp->next;
            c++;
        }

        // 'start' is the first node to be reversed
        ListNode* start = temp->next;
        ListNode* end = start;

        // Push nodes from left to right onto the stack
        while (c <= right && end != nullptr) {
            stc.push(end);
            end = end->next;
            c++;
        }

        // Reverse the nodes by popping from the stack
        while (!stc.empty()) {
            temp->next = stc.top();
            stc.pop();
            temp = temp->next;
        }

        // Connect the reversed part with the remaining list
        temp->next = end;

        // Return the corrected list
        return result->next;
    }
};
