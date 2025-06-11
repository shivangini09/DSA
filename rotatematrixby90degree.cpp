class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        // transpose of matrix
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                swap(matrix[i][j],matrix[j][i]);       // in transpose, diagonal elements remain same 
            }
        }

        // reverse each row
        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
        
    }
};