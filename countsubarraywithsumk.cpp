class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    int count = 0;
    int presum=0;
    map<int,int> mpp;
    mpp[0]=1;
    
    for (int i = 0; i < n; i++) {
        presum+=nums[i];
        int remove = presum-k;
        count+=mpp[remove];
        mpp[presum]++;
        
    }
    
    return count;

 
    }
    
};