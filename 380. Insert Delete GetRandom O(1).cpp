class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        store.clear();
        vec.empty();
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (store.find(val) == store.end()) {
            vec.push_back(val);
            store[val] = vec.size()-1;
            return true;
        }
        return false;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (store.find(val) != store.end()) {
            int last_elem = vec.back();
            vec[store[val]] = last_elem;
            store[last_elem] = store[val];
            vec.pop_back();
            store.erase(val);
            return true;
        }
        return false;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int idx = rand() % vec.size();
        return vec[idx];
    }

private:
    unordered_map<int, int> store;
    vector<int> vec;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
