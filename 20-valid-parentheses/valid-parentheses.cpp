class Solution {
public:
    bool isValid(string s1) {
        stack<char>s;
        int count = 0;
        for(auto ch : s1)
        {
            if(ch == '(' || ch == '{' || ch == '[') s.push(ch);
            else
            {
                if(s.empty()) return false;
                if(ch == ')')
                {
                    if(s.top() == '(') s.pop();
                    else return false;
                }
                if(ch == ']')
                {
                    if(s.top() == '[') s.pop();
                    else return false;
                }
                if(ch == '}')
                {
                    if(s.top() == '{') s.pop();
                    else return false;
                }
            }

        }
            if(s.empty()) return true;
            return false;
    }
};