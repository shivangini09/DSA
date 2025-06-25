// User function Template for C++

class Solution {
  public:
    void dfs(int row, int col,vector<vector<int>>& grid, vector<vector<int>>& vis, vector<pair<int,int>>& vec, int row0, int col0){
        vis[row][col]=1; // mark them visited 
        vec.push_back({row-row0,col-col0});
        int n = grid.size();
        int m = grid[0].size();
        
        // jb bhi we discuss aas paas n padosi delrow and delcol comes
        int delrow[] = {0,1,0,-1};
        int delcol[] = {1,0,-1,0};
        for(int i = 0; i<4; i++){
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];
            if(nrow>=0 && ncol<m && ncol>=0 && nrow<n && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                // calling dfs for the whole island
                dfs(nrow,ncol,grid,vis,vec,row0,col0);
            }
        }
    } 
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>> st;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && vis[i][j]!=1){
                    vector<pair<int,int>> vec;
                    // calling dfs for every island!!!!
                    dfs(i,j,grid,vis,vec,i,j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};
