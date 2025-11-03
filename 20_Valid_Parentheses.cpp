class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (st.empty()) return false; // No match

                char top = st.top();
                if ((c == ')' && top == '(') ||
                    (c == ']' && top == '[') ||
                    (c == '}' && top == '{')) {
                    st.pop(); // matched → remove
                } else {
                    return false; // mismatch
                }
            }
        }

        // ✅ Return true only if all brackets are closed
        return st.empty();
    }
};
