class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n= nums.size();
        int count0 = 0, count1 = 0, count2 = 0;

        for(int i=0; i<n; i++){
            if(nums[i]==0){
                count0++;
            }
            else if(nums[i]==1){
                count1++;
            }
            else{
                count2++;
            }

        }
        for(int i=0 ; i<count0; i++){          // from index 0 to count0
            nums[i]=0;
        }
        for(int i=count0 ; i<count1+count0; i++){           // from index count0 to count1+count0
            nums[i]=1; 
        }
        for(int i=count1+count0 ; i<count2+count1+count0; i++){     // from index count0+count1 to countall
            nums[i]=2;
        }

    return;
    }

};