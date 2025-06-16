class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        generatecombosum(0,current,result,candidates,target);
        return result;
        
    }
private:
    void generatecombosum(int index, vector<int> &current, vector<vector<int>> &result, vector<int>& candidates, int target){
        if(index==candidates.size()){
            if(target==0){        
                result.push_back(current);
            }
            return;
        }
        

        if(candidates[index]<=target){
            current.push_back(candidates[index]);
            generatecombosum(index,current,result,candidates,target-candidates[index]);
            current.pop_back();

        }
        generatecombosum(index+1,current,result,candidates,target);

    }
};