class Solution {
public:
    int countPaths(int i, int j, vector<vector<int>> &dp) {
        dp[0][0]=1;     // reached start
        if(i<0 || j<0) return 0;        // out of bounds

        if(dp[i][j] != -1) return dp[i][j]; // already computed

        int up = countPaths(i-1, j, dp);
        int left = countPaths(i, j-1, dp);

        return dp[i][j] = up + left;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1)); 
        return countPaths(m-1, n-1, dp);
    }
};
