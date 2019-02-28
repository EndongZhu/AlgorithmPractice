/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        vector<int> mem;
        mem.push_back(0);
        for (auto elem : nestedList) {
            if (elem.isInteger()) {
                mem[0] += elem.getInteger();
            } else {
                dfsHelper(elem.getList(), 1, mem);
            }
        }
        int ans = 0;
        for (int i = 0; i < mem.size(); i++) {
            ans += mem[i] * (mem.size() - i);
        }
        return ans;
    }

    void dfsHelper(vector<NestedInteger>& nestedList, int depth, vector<int>& mem) {
        if (mem.size() < depth+1) {
            mem.resize(depth+1, 0);
        }
        for (auto elem : nestedList) {
            if (elem.isInteger()) {
                mem[depth] += elem.getInteger();
            } else {
                dfsHelper(elem.getList(), depth+1, mem);
            }
        }
    }
};
