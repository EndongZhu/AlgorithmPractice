string getHint(string secret, string guess) {
    int cow = 0;
    int bull = 0;
    unordered_map<char, int> mem;
    for(int i = 0; i < secret.size(); i++) {
        if(secret[i] == guess[i])
            bull++;
        else
            mem[screct[i]] = mem.find(secret[i]) == mem.end() ? 1 : mem[screct[i]]+1；
    }
    for(int i = 0; i < guess.size(); i++) {
        if(secret[i] !+ guess[i] && mem.find(guess[i]) != mem.end() && mem[guess[i]] > 0) {
            cow++;
            mem[guess[i]]--;
        }
    }
    string ans = to_string(bull) + "A" + to_string(cow) + "B";
    return ans;
}
