class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, int color, int inicolor, int delrow[], int delcol[]){

        // dfs solution
        ans[row][col]=color;
        int n = image.size();
        int m = image[0].size();
        for(int i=0; i<4; i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol]!=color && image[nrow][ncol]==inicolor){
                dfs(nrow,ncol,ans,image,color,inicolor,delrow,delcol);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;
        int inicolor = image[sr][sc]; // finding the initial color
        int delrow[] = {1,0,-1,0};
        int delcol[] = {0,1,0,-1};
        dfs(sr,sc,ans,image,color,inicolor,delrow,delcol);
        return ans;
    }
};