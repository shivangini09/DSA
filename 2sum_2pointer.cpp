class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // first sort the array though
        int n = nums.size();
        int left = 0;
        int right = n-1;
        while(left<right){
            if(nums[left]+nums[right]==target){
                return {left,right};
            }
            else if(nums[left]+nums[right]<target){
                left++;
            }
            else{
                right--;
            }
        }
        return{};
    }
};