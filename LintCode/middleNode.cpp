//https://www.lintcode.com/problem/1609/
// 链表的中间结点

#include "LintCode.h"

class ListNode
{
public:
	int val;
	ListNode *next;
	ListNode(int val)
	{
		this->val = val;
		this->next = NULL;
	}
};


ListNode* middleNode(ListNode *head)
{
	// write your code here.
	if (!head || !head->next)
	{
		return head;
	}

	ListNode* slow = head;
	ListNode* fast = head;
	while (fast && fast->next)
	{		
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}