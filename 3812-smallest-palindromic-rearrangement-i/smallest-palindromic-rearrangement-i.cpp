class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>freq(26, 0);

        for(auto ch: s) freq[ch - 'a'] += 1;

        string middle;
        string left;

        for(int i = 0; i < 26; i++){
            left += string(freq[i]/2, char(i + 'a'));

            if(freq[i] % 2 != 0) middle = char('a' + i);
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + middle + right;
    }
};