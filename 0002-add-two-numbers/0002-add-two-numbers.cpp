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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode result(0);  // Dummy node to simplify handling of the head node
        ListNode* last = &result;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry > 0) {
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;
            int sum = val1 + val2 + carry;

            carry = sum / 10;
            sum = sum % 10;

            last->next = new ListNode(sum);
            last = last->next;

            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        return result.next;
    }
};
