class Solution {
public:
    int majorityElement(vector<int>& nums) {

    //.  BRUTE FORCE APPROACH 
    //     int n = nums.size();
    //     for(int i=0;i<n;i++){
    //         int count = 1;
    //         for(int j=0;j<n;j++){
    //             if(i!=j && nums[i]==nums[j]){
    //                 count++;
    //             }
    //         if(count>n/2){
    //             return nums[i];
    //             break;
    //         }

    //         }
    //     }
    // return 0;  

    // int n = nums.size();
    // map<int,int> mpp;
    // for(int i=0;i<n;i++){
    //     int a = nums[i];
    //     mpp[a]++;
    //     if(mpp[a]>n/2){
    //         return a;
            
    //     }
    // } 
    // return 0;
    // }

    int candidate = -1;
    int count = 0;
    for(int num:nums){
        if(count==0){
            candidate=num;
            count=1;
        }
        else if(num==candidate){
            count++;
        }
        else{
            count--;
        }
    }
    return candidate;
    }
};