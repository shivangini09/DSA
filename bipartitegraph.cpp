class Solution {
  public:
    bool check(int V, vector<vector<int>> &adj, int start, vector<int> &vis  ){
        queue<int> q;
        q.push(start);   // push the starting node of the component 
        vis[start]=0;          // give a color to the starting node!!
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it: adj[node]){    
                if(vis[it]==-1){      // if we have not put any color on it, we should think
                    q.push(it);
                    vis[it]=!vis[node];       // apne hi rang mein mujhko mat rangde
                }
                else if(vis[it]==vis[node]){       // agar already colored hai toh let me check kahin same toh nhinnn
                    return false;
                }
            }
        }
        return true;
        
    }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto it : edges){      // abki baar edges is in pair forms
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
}

        vector<int> vis(V,-1);
        for(int i=0; i<V;i++){
            if(vis[i]==-1){
                if(check(V,adj,i,vis)==false){
                    return false;
                }
            }
        }
        return true;
    }
};