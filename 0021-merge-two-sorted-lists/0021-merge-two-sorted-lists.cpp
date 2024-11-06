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


	ListNode head(0);
	ListNode* result = &head;


	auto itr1 = list1, itr2 = list2;

	while (itr1 != nullptr && itr2 != nullptr) {
		if (itr1->val > itr2->val) {
			result->next = itr2;
			itr2 = itr2->next;
		}
		else {
			result->next = itr1;
			itr1 = itr1->next;
		}
		result = result->next;
	}

	if (itr1 == nullptr)
	{
		result->next = itr2;
	}
	else {
		result->next = itr1;
	}

	return head.next;
}



};