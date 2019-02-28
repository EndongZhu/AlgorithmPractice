class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL)
            return NULL;

        int cnt = 0;
        ListNode* dummy = head;
        ListNode* start = new ListNode(0);
        start->next = head;
        ListNode* iter = head;
        bool first = 1;
        while(iter != NULL) {
            ++cnt;
            if(cnt == k) {
                ListNode* tmp = iter->next;
                pair<ListNode*,ListNode*> head_tail = reverseSubList(start->next, tmp);
                start->next = head_tail.first;
                head_tail.second->next = tmp;
                iter = tmp;
                cnt = 0;
                if(first) {
                    dummy = head_tail.first;
                    first = 0;
                }
            } else {
                iter = iter->next;
            }
        }
        return dummy;
    }

    pair<ListNode*,ListNode*> reverseSubList(ListNode* node, ListNode* end) {
        if(node == NULL || node->next == NULL)
            return node;
        ListNode* prev = node, cur = node->next;
        while(cur != NULL) {
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        node->next = NULL;
        pair<ListNode*, ListNode*> head_tail(prev, node);
        return head_tail;
    }
};
