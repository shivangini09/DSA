class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> distance(n, vector<int>(m, 0));
        queue<pair<pair<int,int>,int>> q;

        // Push all 1's into the queue and mark them visited
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    vis[i][j] = 1;
                    q.push({{i, j}, 0});
                    
                }
            }
        }

        int delrow[] = {0, 1, 0, -1};
        int delcol[] = {1, 0, -1, 0};

        // BFS
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            distance[row][col] = steps;

            for(int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] ) {
                    // vis[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, steps + 1});
                    vis[nrow][ncol] = 1;
                }
            }
        }

        return distance;
    }
};
