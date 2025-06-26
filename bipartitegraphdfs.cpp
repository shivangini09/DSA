class Solution {
public:
    bool dfs(int start, int col,vector<vector<int>>& graph, vector<int> &color ){
        color[start]=col; //color the node

        for(auto it : graph[start]){        // color the adjacent nodes if not colored 
            if(color[it]==-1){
                if(dfs(it,!col,graph,color)==false){
                    return false;        // if any dfs returns false, we are false are'nt we!!
                }
            }
            else if(color[it]==color[start]){          // agar color mil gaya toh na ji naa
                    return false;
                }
        
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);

        for(int i=0; i<n; i++){         // shit i pull out to deal with connected components
            if(color[i]==-1){
                if(dfs(i,0,graph,color)==false){
                    return false;
                }
            }
        }
        return true;
        
    }
};