class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        memset(keys, -1, sizeof(int)*20001);
        memset(values, -1, sizeof(int)*20001);
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int idx = key % 100001;
        while (keys[idx] != -1)
            idx = (idx+1) % 100001;
        keys[idx] = key;
        values[idx] = value;
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int idx = key % 100001;
        while (keys[idx] != key && keys[idx] != -1)
            idx = (idx+1) % 100001;
        int res = keys[idx] != -1 ? values[idx] : -1
        return res;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int idx = key % 100001;
        while (keys[idx] != key && keys[idx] != -1)
            idx = (idx+1) % 100001;
        keys[idx] = -1;
        values[idx] = -1;
    }
private:
    int keys[100001];
    int values[100001];
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */
