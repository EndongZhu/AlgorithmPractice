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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        ListNode* l3 = addList(l1, l2);
        l3 = reverseList(l3);
        return l3;
    }

    ListNode* reverseList(ListNode* l) {
        ListNode* prev = l;
        ListNode* iter = l->next;
        prev->next = NULL;
        while(iter != NULL) {
            ListNode* temp = iter->next;
            iter->next = prev;
            prev = iter;
            iter = temp;
        }
        return prev;
    }

    ListNode* addList(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* iter1 = l1;
        ListNode* iter2 = l2;
        ListNode* head = new ListNode(-1);
        ListNode* iter = head;
        while (iter1 && iter2) {
            int a = iter1 == NULL ? 0 : iter1->val;
            int b = iter2 == NULL ? 0 : iter2->val;
            iter->next = new ListNode((a + b + carry) % 10);
            carry = (a + b + carry) / 10;
            iter1 = iter1->next;
            iter2 = iter2->next;
            iter = iter->next;
        }
        if (carry) {
            ListNode* new_node = new ListNode(carry);
            iter->next = new_node;
        }
        return head;
    }
};
