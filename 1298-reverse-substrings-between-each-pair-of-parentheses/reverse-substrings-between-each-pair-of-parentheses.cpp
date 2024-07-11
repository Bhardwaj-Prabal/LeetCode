class Solution {
public:
    string reverseParentheses(string s) {
       stack<string> st;
    string res = "";
    
    for (char c : s) {
        if (c == '(') {
            st.push(res);
            res = "";
        } else if (c == ')') {
            reverse(res.begin(), res.end());
            res = st.top() + res;
            st.pop();
        } else {
            res += c;
        }
    }
    
    return res;
    }
};