class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n = g.size();
        int m = s.size();
        int cookie = 0;
        int kid = 0;
        while(cookie<m && kid<n){
            if(g[kid]<=s[cookie]){
                kid++;
            }
            cookie++;             // even if the need is not satisfied we move the cookie counter 
        }                         // to see potential of next cookie
        return kid;
        
    }
};