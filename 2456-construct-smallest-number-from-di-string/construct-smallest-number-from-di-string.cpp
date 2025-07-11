class Solution {
public:
    string smallestNumber(string pattern) {
    if (pattern.length() > 8)
        return "String length exceeds";

    string result = "";
    stack<int> st;
    int num = 1;

    for (int i = 0; i <= pattern.length(); i++) {
        st.push(num++);
        
        if (i == pattern.length() || pattern[i] == 'I') {
            while (!st.empty()) {
                result += to_string(st.top());
                st.pop();
            }
        }
    }

    return result;
    }
};