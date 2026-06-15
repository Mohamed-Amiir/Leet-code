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
        int n = 0, i = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            n++;
            temp = temp->next;
        }
        if(n == 1)return nullptr;
        int mid = n / 2;
        temp = head;
        ListNode *beforeMid = nullptr, *afterMid= nullptr;
        while (temp != nullptr) {
            if (i == mid - 1) {
                beforeMid = temp;
            } else if (i == mid + 1) {
                afterMid = temp;
            }

            temp = temp->next;
            i++;
        }
        beforeMid->next = afterMid;
        return head;
    }
};