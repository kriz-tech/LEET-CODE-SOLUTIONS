class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int s_len = s.length(), t_len = t.length();
        if(s_len != t_len) return 0;

        unordered_map<char, char>mapst, mapts;

        for(int i = 0; i < s.size(); i++){
            char a = s[i], b = t[i];

            if((mapst.count(a) && mapst[a] != b) || (mapts.count(b) && mapts[b] != a ))
                return false;

            mapst[a] = b;
            mapts[b] = a;
        }
        return true;
    }
};