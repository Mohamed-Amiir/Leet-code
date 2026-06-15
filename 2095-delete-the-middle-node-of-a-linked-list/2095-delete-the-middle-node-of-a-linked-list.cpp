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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next)return nullptr;
        int n = 0, i = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            n++;
            temp = temp->next;
        }
        int mid = n / 2;
        temp = head;
        ListNode *beforeMid = nullptr, *afterMid = nullptr;
        while (temp != nullptr) {
            if (i == mid - 1) {
                temp ->next = temp->next->next;
                return head;
            } 
            temp = temp->next;
            i++;
        }
        return nullptr;
    }
};