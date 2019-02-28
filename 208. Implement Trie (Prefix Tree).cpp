struct node {
    char  val;
    unordered_map<char, node*> child;
    node(int x) : val(x), child(unordered_map<char, node*>()) {}
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        head = new node('#');
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        node* iter = head;
        for (int i = 0; i < word.size(); i++) {
            if (iter->child.find(word[i]) == iter->child.end()) {
                node* new_node = new node(word[i]);
                iter->child[word[i]] = new_node;
                iter = new_node;
            } else {
                iter = iter->child[word[i]];
            }
        }
        iter->child['#'] = new node('#');
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        node* iter = head;
        for(int i = 0; i < word.size(); i++) {
            if (iter->child.find(word[i]) == iter->child.end()) {
                return false;
            }
            iter = iter->child[word[i]];
        }
        return iter->child.find('#') != iter->child.end();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        node* iter = head;
        for(int i = 0; i < prefix.size(); i++) {
            if (iter->child.find(prefix[i]) == iter->child.end()) {
                return false;
            }
            iter = iter->child[prefix[i]];
        }
        return iter->child.size() > 0;
    }

private:
    node* head;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
