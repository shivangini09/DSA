// User function Template for C++

class Solution {
  public:
    string postToInfix(string exp) {
        // Write your code here
        stack<string> st;
        for(char ch: exp){
            if(isalnum(ch)){
                st.push(string(1,ch));
            }
            else{
                string s1 = st.top();
                st.pop();
                string s2 = st.top();
                st.pop();
                string s = "("+s2+ch+s1+")";
                st.push(s);
            }
        }
        return st.top();
    }
};