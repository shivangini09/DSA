class Solution {
public:
    int lowerbound(vector<int>& nums, int target){
        int low = 0;
        int high = nums.size()-1;
        int ans = nums.size();
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]>=target){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }

    int upperbound(vector<int>& nums, int target){
        int low = 0;
        int high = nums.size()-1;
        int ans = nums.size();
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]>target){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;

    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lowerbound(nums,target);  // find lower bound
        if(lb==nums.size() || nums[lb]!=target){
            return {-1,-1};
        }
        int ub = upperbound(nums,target);
        return {lb,ub-1};
        
    }
};