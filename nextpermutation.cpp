class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n= nums.size();
        int index=-1;
        for(int i=n-2; i>=0; i--){          // finding the index where the shift can happen 
            if(nums[i]<nums[i+1]){ 
                index = i;
                break;
            }
        }
        if(index==-1){
            reverse(nums.begin(),nums.end());         // if the array is last of order, return the first one!
             
        }
        else{
            for(int i=n-1; i>index; i--){          // find the first greater number

                if(nums[i]>nums[index]){
                    swap(nums[i],nums[index]);
                    break;
                }
            
            }
            reverse(nums.begin()+index+1,nums.end());          // you want just the next greater
 


    
        }
        }

        
};