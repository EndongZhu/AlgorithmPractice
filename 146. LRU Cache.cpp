struct CacheNode {
    int key;
    int val;
    CacheNode *prev;
    CacheNode *next;
    CacheNode(int x, int y): key(x), val(y), prev(NULL), next(NULL) {}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        max_num = capacity;
        size = 0;
        head = new CacheNode(-1, -1);
        tail = new CacheNode(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if(mem.find(key) == mem.end())
            return -1 ;
        int ans = mem[key]->val ;
        updateLRU(key);
        return ans ;
    }

    void put(int key, int value) {
        if(mem.find(key) != mem.end()) {
            mem[key]->val = value ;
            updateLRU(key);
        }
        else if(size < max_num) {
            mem[key] = new CacheNode(key, value);
            updateLRU(key);
            ++size ;
        }
        else {
            CacheNode* last = tail->prev;
            mem.remove(last->key);
            tail->prev = last->prev;
            last->prev = tail;
            delete(last);
            mem[key] = new CacheNode(key, value);
            updateLRU(key);
        }
    }
private:
    int size;
    int max_num;
    map<int,CacheNode*> mem;
    CacheNode* head;
    CacheNode* tail;
    void updateLRU(int key) {
        CacheNode* first = head->next;
        head->next = mem[key];
        mem[key]->next = first;
        mem[key]->prev = head;
        first->prev = mem[key];
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
