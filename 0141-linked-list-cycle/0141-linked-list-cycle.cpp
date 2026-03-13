/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode* head) {
        if(head == NULL)return false;
        unordered_map<ListNode*, bool> visited;
        ListNode* temp = head;
        while (true) {
            if (visited[temp] == true)
                return true;
            else
                visited[temp] = true;
            if (temp->next == NULL)
                return false;
            else
                temp = temp->next;
        }
        return true;
    }
};