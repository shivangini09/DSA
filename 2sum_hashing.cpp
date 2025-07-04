class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();
        map<int,int> mpp;
        for(int i=0; i<n; i++){
            int el = nums[i];
            int more = target-el;
            if(mpp.find(more)!=mpp.end()){
                return {mpp[more],i};
            }
            mpp[el]=i;
        }
    return{};
    }
};
