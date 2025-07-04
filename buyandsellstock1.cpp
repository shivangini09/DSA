class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int mini = prices[0];
        int n = prices.size();
        for(int i=1; i<n; i++){
            int cost = prices[i]-mini;          // maxprofit that can be extracted from selling stock on that day!
            maxprofit = max(maxprofit,cost);
            mini = min(mini,prices[i]);                     // update the minimum
        }
        return maxprofit;
        
    }
};