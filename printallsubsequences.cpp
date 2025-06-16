class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> current;
        int n = nums.size();
        generatesubsets(0,n,nums,current,results);
        return results;


        
    }
private:
    void generatesubsets(int index,int n,vector<int> &nums,vector<int> &current,vector<vector<int>> &results){
        if(index==n){
            results.push_back(current);
            return;
        }
        current.push_back(nums[index]);     // take the element
        generatesubsets(index+1,n,nums,current,results);
        current.pop_back();       // we do not take it!
        generatesubsets(index+1,n,nums,current,results);
    }
};