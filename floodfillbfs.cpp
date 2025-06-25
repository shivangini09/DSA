class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicolor = image[sr][sc];         // initial color 
        queue<pair<int,int>> q;              // QUEUE FOR BFS
        // vector<vector<int>> vis;

        if (inicolor == color) return image;        // IMPORTANT TO AVOID INFINITE LOOPS AND ALL
           
        int n = image.size();
        int m = image[0].size();
        q.push({sr,sc});

        int delrow[] = {0,1,0,-1} ;
        int delcol[] = {-1,0,1,0};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            image[r][c] = color;
            for(int i=0; i<4; i++){
                int row = r + delrow[i];     // to cover all AAS PAAS VALE!!!
                int col = c + delcol[i];
                if(row>=0 && row<n && col>=0 && col<m && image[row][col] == inicolor){
                    // ALL THE NECESSARY CONDITIONS HAVE BEEN APPLIED
                    q.push({row,col});




                }
            }
        



        }


    return image;  
    }
};