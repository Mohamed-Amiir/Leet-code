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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* result = new ListNode();
        ListNode *fast = head, *last = head, *itr = result;
        stack<int> st;
        int c = k + 1;
        while (fast) {
            c--;
            if (c == 0) {
                while (!st.empty()) {
                    ListNode* node = new ListNode(st.top());
                    st.pop();
                    itr->next = node;
                    itr = node;
                }
                c = k;
                last = fast;
            }
            st.push(fast->val);
            fast = fast->next;
        }
        if (!st.empty()) {
            if (st.size() == k) {
                while (!st.empty()) {
                    ListNode* node = new ListNode(st.top());
                    st.pop();
                    itr->next = node;
                    itr = node;
                }
            } else
                itr->next = last;
        }
        return result->next;
    }
};