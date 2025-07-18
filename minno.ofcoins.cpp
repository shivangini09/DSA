// User function Template for C++

class Solution {
  public:
    vector<int> minPartition(int N) {
        // code here
        vector<int> ans;
        vector<int> denomination = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        int n = 10;
        for(int i=9; i>=0; i--){
            while(N>=denomination[i]){
                N-=denomination[i];
                ans.push_back(denomination[i]);
            }
        }
        return ans;
        
    }
};