class Solution {
public:
    int minpath(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &grid) {
        if (i == 0 && j == 0) {
            return grid[i][j];
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int up = INT_MAX, left = INT_MAX;
        if (i > 0) up = minpath(i-1, j, dp, grid) + grid[i][j];
        if (j > 0) left = minpath(i, j-1, dp, grid) + grid[i][j];

        return dp[i][j] = min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return minpath(n-1, m-1, dp, grid);
    }
};
