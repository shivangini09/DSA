class Solution {
public:

    // Largest Histogram Area Function
    int largesthistrec(vector<int> &heights){
        stack<int> st;
        int maxarea = 0;
        int n = heights.size();
        
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int ind = st.top();
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxarea = max(maxarea, heights[ind] * width);
            }
            st.push(i);
        }
        
        // Remaining elements in stack
        while(!st.empty()){
            int ind = st.top();
            st.pop();
            int width = st.empty() ? n : n - st.top() - 1;
            maxarea = max(maxarea, heights[ind] * width);
        }
        
        return maxarea;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size();
        
        vector<int> heights(m, 0); // heights of histogram bars
        int maxarea = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1'){
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }
            maxarea = max(maxarea, largesthistrec(heights));
        }
        
        return maxarea;
    }
};
