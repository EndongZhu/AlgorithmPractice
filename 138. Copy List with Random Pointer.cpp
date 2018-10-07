RandomListNode *copyRandomList(RandomListNode *head)
{
    if(head == NULL)
        return NULL ;

    RandomListNode* iter = head ;
    map<RandomListNode*, int> node2pos ;
    int pos = 0 ;
    while(iter != NULL) {
        node2pos[iter] = pos ;
        iter = iter->next ;
        ++pos;
    }

    map<int, RandomListNode*> pos2node ;
    pos = 0 ;
    iter = head ;
    RandomListNode* copyList = new RandomListNode(head->label) ;
    RandomListNode* copyList_iter = copyList ;
    while(iter != NULL) {
        copyList_iter->next = iter->next == NULL ? NULL : new RandomListNode(iter->next->label) ;
        pos2node[pos] = copyList_iter ;
        iter = iter->next ;
        copyList_iter = copyList_iter->next ;
        ++pos ;
    }

    iter = head ;
    copyList_iter = copyList ;
    while(iter != NULL) {
        if(iter->random == NULL) {
            copyList_iter->random = NULL ;
        }
        else {
            int random_pos = node2pos[iter->random] ;
            RandomListNode* random_addr = pos2node[random_pos] ;
            copyList_iter->random = random_addr ;
        }
        iter = iter->next ;
        copyList_iter = copyList_iter->next ;
    }

    return copyList;
}
