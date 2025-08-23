class Solution {
public:
    int minCost(vector<int>& height) {
        int n = height.size();
        int prev = 0;   // dp[i-1]
        int prev2 = 0;  // dp[i-2]

        for(int i = 1; i < n; i++){
            int singlejump = prev + abs(height[i] - height[i-1]);
            int doublejump = INT_MAX;
            if(i > 1){
                doublejump = prev2 + abs(height[i] - height[i-2]);
            }
            int cur = min(singlejump, doublejump);
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
};
