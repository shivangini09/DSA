class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int temp = nums[0];
        for(int i=0; i<n-1; i++){
            nums[i]=nums[i+1];        // making each element , the next element
        }
        nums[n-1]=temp;               // last element ofc needed that 
        
        
    }
};