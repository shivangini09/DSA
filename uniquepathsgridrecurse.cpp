class Solution {
public:
    int countPaths(int i, int j) {
        if(i==0 && j==0) return 1; // reached start
        if(i<0 || j<0) return 0;   // out of bounds
        int up = countPaths(i-1, j);
        int left = countPaths(i, j-1);
        return up + left;
    }

    int uniquePaths(int m, int n) {
        return countPaths(m-1, n-1); // start from bottom-right
    }
};
