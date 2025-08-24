class Solution {
public: 
    int uniquepaths(vector<vector<int>> &dp, int i, int j, vector<vector<int>> &obstacleGrid){
        if(i>=0 && j>=0 && obstacleGrid[i][j]==1){
            return 0;
        }
        if(i==0 && j==0){
            return 1;
        }
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int up = uniquepaths(dp, i-1, j,obstacleGrid);
        int left = uniquepaths(dp, i, j-1,obstacleGrid);
        dp[i][j] = up+left;
        return dp[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return uniquepaths(dp, m-1, n-1,obstacleGrid);

        
    }
};