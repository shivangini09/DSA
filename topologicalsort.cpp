class Solution {
  public:
    void dfs(int node,vector<vector<int>> &adj, vector<int> &vis, stack<int> &st ){
        vis[node]=1; //mark it visited
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,st);
            }
        }
        st.push(node);
        
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // converting it into adjacency list!!
        int n = edges.size();
        vector<vector<int>> adj(V);       // define the size because u need to access a particular index!!
        for(auto it: edges){
            int u = it[0];  // the owner of the edge
            int v = it[1];    // in the adj right now!!
            
            adj[u].push_back(v);
        }
        stack<int> st;
        vector<int> vis(V,0);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                // if yet not visited, then call dfs for it..
                dfs(i,adj,vis,st);
            }
        }
        vector<int> ans;
        for(int i=0; i<V; i++){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};