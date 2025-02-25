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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
// HELLO WORLD
	ListNode head(0);
	ListNode* result = &head;


	while (list1 != nullptr && list2 != nullptr) {
		if (list1->val > list2->val) {
			result->next = list2;
			list2 = list2->next;
		}
		else {
			result->next = list1;
			list1 = list1->next;
		}
		result = result->next;
	}

	if (list1 == nullptr)
	{
		result->next = list2;
	}
	else {
		result->next = list1;
	}

	return head.next;
}



};
