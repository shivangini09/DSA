class Solution {
  public:
    string infixToPostfix(string& s) {
        stack<char> st;
        string res;     // answer

        for (char c : s) {
            // If operand, add to result
            if (isalnum(c)) {
                res += c;
            }
            // If '(', push to stack
            else if (c == '(') {
                st.push(c);
            }
            // If ')', pop till '('
            else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    res += st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop(); // Pop '('
            }
            // Operator encountered
            else {
                while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                    res += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }

        // Pop remaining operators
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        return res;
    }

  private:
    int precedence(char c) {
        if (c == '^') return 3;
        if (c == '*' || c == '/') return 2;
        if (c == '+' || c == '-') return 1;
        return -1;
    }
};
