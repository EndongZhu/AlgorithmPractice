#include<iostream>
using namespace std ;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) 
{
	ListNode* dummy = new ListNode(-1) ;
	ListNode* iter = dummy ;
	while(head)
	{
		if(head->next && head->val == head->next->val)
		{
			int x = head->val ;
			while(head->val == x)
				head = head->next ;
		}
		else
		{
			iter->next = head ;
			head = head->next ;
			iter = iter->head ;
		}
	}
	return dummy->next ;
}

int main()
{
	ListNode* head = new ListNode(1) ;
	head->next = new ListNode(2) ;
	head->next->next = new ListNode(3) ;
	head = deleteDuplicates(head) ;
	cout<<head->val<<endl ;
}
