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
ListNode* rev(ListNode* head) {
    ListNode* prev = nullptr;

    while (head) {
        ListNode* nxt = head->next;
        head->next = prev;
        prev = head;
        head = nxt;
    }

    return prev;
}
    int pairSum(ListNode* head) {
        ListNode *tail = head, *mid = head, *temp;
        int n = 0, i = 0,result = 0;
        while (tail) {
            tail = tail->next;
            n++;
        }
        int half = n/2;
        while (i < half) {
            mid = mid->next;
            i++;
        }
        ListNode* itr = rev(mid);
        while(half--){
            result = max(result, itr->val+head->val);
            head = head->next;
            itr = itr->next;
        }
        return result;
    }
};