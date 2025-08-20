class Solution {
public:
    int maxsum(vector<int> &nums){
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        
        int prev = nums[0];
        int prev2 = 0;
        
        for(int i=1; i<n; i++){
            int take = nums[i];
            if(i > 1){
                take += prev2;
            }
            int nottake = prev;
            int cur = max(take, nottake);
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];  // only one house
        
        vector<int> temp1, temp2;
        for(int i=0; i<n; i++){
            if(i != 0) temp1.push_back(nums[i]);       // exclude first
            if(i != n-1) temp2.push_back(nums[i]);     // exclude last
        }
        
        return max(maxsum(temp1), maxsum(temp2));
    }
};
