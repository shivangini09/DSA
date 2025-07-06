class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        // brute force soln 
        int n = nums.size();
        vector<int> nge(n,-1);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<i+n; j++){
                int ind = j%n;
                if(nums[ind]>nums[i]){
                    nge[i]=nums[ind]; 
                    break;         // the next greater
                }
            }
        }
        return nge;
        
    }
};