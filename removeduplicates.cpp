class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        for(int j=1; j<n; j++){       // looping over array
            if(nums[j]!=nums[i]){         // if our element is unique 
                nums[i+1]=nums[j];        // we make the next element unique
                i++;                      // now our comparison is from this element 
            }
        }
        return i+1;                       // reurn i+1 bec i is starting from 0;
    }
};