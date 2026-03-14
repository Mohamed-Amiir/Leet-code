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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr)return head;
        unordered_map<int, int> dup;
        ListNode* temp = head;
        ListNode* result = new ListNode();
        ListNode* cur = new ListNode();
        while (temp != nullptr) {
            dup[temp->val]++;
            if(temp->next == nullptr)break;
            temp = temp->next;
        }

        temp = head;
        int n = 0;
        while (temp != nullptr) {
            if (n == 0) {
                if (dup[temp->val] == 1) {
                    result->val = temp->val;
                    cur = result;
                    n++;
                }
            } else {
                if (dup[temp->val] == 1) {

                    ListNode* newNode = new ListNode(temp->val);
                    cur->next = newNode;
                    cur = newNode;
                }
            }
            if(temp->next == nullptr)break;
            temp = temp->next;
        }
        if(n==0)return nullptr;
        return result;
    }
};