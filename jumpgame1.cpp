class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxind = 0;
        for(int i=0; i<nums.size(); i++){
            if(i>maxind){
                // we will not reach you darling
                return false;
            }
            maxind = max(maxind,i+nums[i]);        // we can reach miles
        }
        return true;

    }
};