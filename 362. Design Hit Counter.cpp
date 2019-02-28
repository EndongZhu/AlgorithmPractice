class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        hits.clear();
    }

    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        hits.push(timestamp);
    }

    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        if (hits.size() == 0) {
            return 0;
        }
        while (!hits.empty() && timestamp > hits.front()+300) {
            hits.pop();
        }
        return hits.size();
    }
private:
    queue<int> hits;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
