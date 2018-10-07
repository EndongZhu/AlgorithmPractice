bool hasCycle(ListNode *head) {
    if(head == NULL)
        return false ;
    ListNode* ptr1 = head ;
    ListNode* ptr2 = head ;
    while(ptr1 != NULL && ptr2 != NULL) {
        ptr1 = ptr1->next ;
        ptr2 = ptr2->next == NULL ? NULL : ptr2->next->next ;
        if(ptr1 == ptr2)
            break ;
    }
    if(ptr1 == ptr2 && ptr1 != NULL)
        return true ;
    else
        return false ;
}
