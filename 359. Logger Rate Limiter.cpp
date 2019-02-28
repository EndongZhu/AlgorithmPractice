class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
        mem.clear();
    }

    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if(mem.find(message) == mem.end()) {
            mem[message] = timestamp;
            return true;
        } else if(mem[message] + 10 < timestamp){
            mem[message] = timestamp;
            return true;
        } else {
            return false;
        }
    }
private:
    unordered_map<message, int> mem;
};
