class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int longest = 1;
        unordered_set<int> st;
        for(int i=0; i<n; i++){
            st.insert(nums[i]);            // everything is in the set now
        }
        for(auto it:st){
            if(st.find(it-1)==st.end()){             // if ele-1 not available , it can be a flag bearer
                int x = it;
                int cur=1;                           // the length of sequence as of now is 1
                while(st.find(x+1)){                 // counting kitne hai iske peeche 
                    cur+=1;
                    x=x+1;
                }
                longest = max(longest,cur);            // checking if it is the max!
            }

        }
        return longest;

        
    }
};