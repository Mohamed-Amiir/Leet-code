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
    int pairSum(ListNode* head) {
        int c = 0, mirror = 1, n = 0;

        ListNode* temp = head;
        while (temp != nullptr) {
            n++;
            temp = temp->next;
        }
        vector<int> sums(n / 2);
        temp =  head;
        int result = 0;
        while (temp != nullptr) {
            if (c < n / 2) {
                sums[c] = temp->val;
            } else {
                int mirIndex = n / 2 - mirror;
                sums[mirIndex] += temp->val;
                result = max(result,sums[mirIndex]);
                mirror++;
            }
            temp = temp->next;
            c++;
        }
        return result;
    }
};