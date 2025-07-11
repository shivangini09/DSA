class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;
        for(int i=0; i<n; i++){
            if(!dq.empty() && dq.front()<=(i-k)){
                dq.pop_front();      // pop the elements that do not fit into the window
            }
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();      // pop the elements which are not the potential maximum
            }
            dq.push_back(i);        // push it
            if(i>=k-1){
                ans.push_back(nums[dq.front()]);        // windows happens after k-1 index
            }
        }
        return ans;            
        
    }
};