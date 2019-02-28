bool isMonotonic(vector<int>& A) {
    bool increasing = true;
    bool decreasing = true;
    for(int i = 1; i < A.size(); i++) {
        if(A[i] > A[i-1])
            decreasing = false;
        if(A[i] < A[i-1])
            increasing = false;
    }
    return increasing || decreasing;
}
