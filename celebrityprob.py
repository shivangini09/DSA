# / User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n = mat.size();
        int top=0;
        int down=n-1;
        while(top<down){
            if(mat[top][down]==1){
                top++;
            }
            else if(mat[down][top]==1){
                down--;
            }
            else{
                top++;
                down--;
            }
        }
        if(top>down){
            return -1;
        }
        int i = 0;
        while(i<n){
            if(i!=top && (mat[top][i]!=0 || mat[i][top]!=1)){
                return -1;
            }
            
            i++;
        }
        return top;
    }
};