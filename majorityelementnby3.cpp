class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ls;
        int count1 = 0, count2 = 0;
        int el1 = 0, el2 = 1; // initialize to two different values

        // Step 1: Find potential candidates
        for(int num : nums) {
            if(num == el1) count1++;
            else if(num == el2) count2++;
            else if(count1 == 0) {
                el1 = num;
                count1 = 1;
            }
            else if(count2 == 0) {
                el2 = num;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }

        // Step 2: Verify the counts
        count1 = count2 = 0;
        for(int num : nums) {
            if(num == el1) count1++;
            else if(num == el2) count2++;
        }

        if(count1 > n / 3) ls.push_back(el1);
        if(count2 > n / 3) ls.push_back(el2);

        return ls;
    }
};

