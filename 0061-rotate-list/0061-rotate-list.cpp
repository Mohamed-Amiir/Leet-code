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
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == nullptr) return head; 
        int n = 0;
        ListNode* temp = head;
        ListNode* result = new ListNode();
        ListNode* tail = new ListNode();
        while(temp){
            n++;
            if(temp->next == nullptr)tail = temp;
            temp = temp->next;
        }
        k = k % n;
        if(n==1 ||k==0)return head;
        temp = head;
        while(temp){
            if(n == k + 1){
                result = temp->next;
                tail->next = head;
                temp->next = nullptr;
                break;
            }
            n--;
            temp = temp ->next;
        }
        return result;
    }
};