class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        vector<vector<int>> result;
        for(int i=1; i<=n; i++){
            vector<int> row;
            int ans=1;
            row.push_back(ans);
            // loop to hover over columns one by one
            for(int j=1; j<i; j++){
                ans=ans*(i-j);   // ans = ans*(row-col)
                ans=ans/j;
                row.push_back(ans);
            }
            result.push_back(row);
        }
        return result;
    }
};