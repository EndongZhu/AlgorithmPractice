int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int start = 0;
    int total = 0;
    int tank = 0;
    int len = gas.size();
    for (int i = 0; i < len; i++){
        tank += gas[i]-cost[i];
        if(total < 0) {
            start = i+1;
            total += tank;
            tank = 0
        }
    }
    return total+tank >= 0? start: -1
}
