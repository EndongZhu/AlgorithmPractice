class cmp {
public:
    bool operator() (pair<int,int>& a, pair<int,int>& b)
    {
        if(a.second == b.second)
            return a.first < b.first ;
        else
            return a.second < b.second ;
    }
};

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    priority_queue<pair<int,int>, std::vector<int>, cmp> pq ;
    for(int i = 0; i < arr.size(); i++) {
        pair<int,int> p(arr[i], abs(arr[i]-x)) ;
        priority_queue.push(p) ;
    }
    vector<int> ans;
    while(k--) {
        ans.push_back(priority_queue.top().first) ;
        priority_queue.pop() ;
    }
    return ans ;
}
