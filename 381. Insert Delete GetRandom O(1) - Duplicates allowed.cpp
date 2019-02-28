class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        vec.push_back(val);
        if (store.count(val)){
            store[val].insert(vec.size()-1);
            return false;
        } else {
            unordered_set<int> temp;
            temp.insert(vec.size()-1);
            store[val] = temp;
            return true;
        }
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (store.count(val)) {
            int idx = *(store[val].begin());
            store[val].erase(idx);
            if (store[val].size() == 0) {
                store.erase(val);
            }
            int last_elem = vec[vec.size()-1];
            vec[idx] = last_elem;
            store[last_elem].erase(vec.size()-1);
            store[last_elem].insert(idx);
            vec.pop_back();
            return true;
        }
        return false;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        int idx = rand() % vec.size();
        return vec[idx];
    }
private:
    vector<int> vec;
    unordered_map<int, unordered_set<int>> store;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
