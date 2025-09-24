class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        int upper = 0;

        for(auto ch : word) if(isupper(ch)) upper++;
        if(upper == n) return true;
        if(upper == 0) return true;
        if(upper == 1 && isupper(word[0])) return true;
        return false;
    }
};