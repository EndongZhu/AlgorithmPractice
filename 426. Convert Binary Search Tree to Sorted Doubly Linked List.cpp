Node* treeToDoublyList(Node* root) {
    if (root == NULL)
        return NULL;
    Node* llist = treeToDoublyList(root->left);
    Node* rlist = treeToDoublyList(root->right);
    root->left = root;
    root->right = root;
    return concat(concat(llist, root), rlist);
}

Node* concat(Node* llist, Node* rlist) {
    if(llist == NULL)
        return rlist;
    if(rlist == NULL)
        return llist;

    Node* ltail = llist->left;
    Node* rtail = rlist->left;
    rlist->left = ltail;
    ltail->right = rlist;
    llist->left = rtail;
    rtail->right = llist;

    return llist;
}
