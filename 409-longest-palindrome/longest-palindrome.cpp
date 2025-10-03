class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int>freq;
        for(auto ch : s) freq[ch]++;

        int length = 0;
        bool odd_found = false;

        for(auto [ch, count] : freq){
            length += (count / 2) * 2;
            if(count % 2 == 1) odd_found = true;
        }
        if(odd_found) length++;
        return length;
    }
};