class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();                 // no. of rows
        int m = grid[0].size();             // no. of columns

        queue<pair<pair<int, int>, int>> q;     // queue for bfs is mandatory
        vector<vector<int>> vis(n, vector<int>(m, 0)); // Initialize `vis` with dimensions and values

        // Pushing all initially rotten oranges into the queue


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});     // Push position and time
                    vis[i][j] = 2;
                }
            }
        }

        int drow[] = {-1, 0, 1, 0};        // Direction vectors for rows
        int dcol[] = {0, 1, 0, -1};       // Direction vectors for columns
        int time = 0;

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();

            // Update time to the maximum value seen so far
            time = max(time, t);

            for (int i = 0; i < 4; i++) {        // upper neeche daayein baayein all check
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                    grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0) {
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2; // Mark as visited (rotten)
                }
            }
        }

        // Check if any fresh oranges remain
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j] != 2) {
                    return -1; // Impossible to rot all oranges
                }
            }
        }

        return time;
    }
};
