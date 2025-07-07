class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.size();
        for(int i=0; i<n; i++){
            while(!st.empty() && k>0 && (st.top()-'0')>(num[i]-'0')){
                st.pop();
                k--;       // everytime we are able to pop, we reduce the k
            }
            st.push(num[i]);
        }
        // dealing with edge cases 
        while(k>0){
            st.pop();
            k--;         // if the string now seemed sorted, remove elements from the last
        }

        if(st.empty()){
            return "0";      // agar kuch nhi bacha
        }

        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();   // add in result arrayy
        }
        while(res.size()!=0 && res.back()=='0'){
            res.pop_back();               // pop back the zeroes which add no value , the zeroes from the beginning
        }
        reverse(res.begin(),res.end());        // dont forget it to reverse it though
        if(res==""){                 // what if all 0s
            return "0";
        }
        return res;
        
    }
};