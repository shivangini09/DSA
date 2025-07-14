class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxarea = 0;
        int n = heights.size();
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int ind = st.top();
                st.pop();
                int nse = i; // kyuki jisko bhi ye bahr nikaal raha usska ye nse hai..

                if(st.empty()){
                    maxarea=max(maxarea,(heights[ind]*(nse)));
                }
                else{
                    maxarea = max(maxarea,(heights[ind]*(nse-st.top()-1)));
                }
                
            }
            st.push(i);
        }
        // empty the stack 
        // now
        while(!st.empty()){
             // as there is no nse
            int ind = st.top();
            st.pop();
            if(st.empty()){
                int pse = -1;
                int area = heights[ind]*(n-pse-1);
                maxarea  = max(maxarea,area);
            }
            else{
                int pse = st.top();
                int area = heights[ind]*(n-pse-1);
                maxarea  = max(maxarea,area);
            }
            
        }
        return maxarea;
        
    }
};