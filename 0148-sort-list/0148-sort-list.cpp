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
ListNode* getMid(ListNode* head) {
	if (head == nullptr || head->next == nullptr) {
		return head;
	}
	ListNode* slow = head;
	ListNode* fast = head->next;

	while (fast != nullptr && fast->next != nullptr) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

ListNode* merge(ListNode* left, ListNode* right) {

	ListNode dummy;
	ListNode* itr = &dummy;

	while (left != nullptr && right != nullptr) {
		if (left->val <= right->val) {
			itr->next = left;
			left = left->next;
		}
		else {
			itr->next = right;
			right = right->next;
		}
		itr = itr->next;
	}

	if (left != nullptr) {
		itr->next = left;
	}
	else if (right != nullptr) {
		itr->next = right;
	}

	return dummy.next;
}

// Function to perform merge sort on a linked list
ListNode* mergeSort(ListNode* head) {
	if (head == nullptr || head->next == nullptr) {
		return head;
	}

	ListNode* mid = getMid(head);
	ListNode* left = head;
	ListNode* right = mid->next;
	mid->next = nullptr;

	left = mergeSort(left);
	right = mergeSort(right);

	return merge(left, right);
}

ListNode* sortList(ListNode* head) {
    ListNode* result = mergeSort(head);
    return result;  // Return the pointer to the sorted list
}

};