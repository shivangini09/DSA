class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        // kahn algorithm
        // converting it into adjacency list!!
        int n = edges.size();
        vector<vector<int>> adj(V);       // define the size because u need to access a particular index!!
        for(auto it: edges){
            int u = it[0];  // the owner of the edge
            int v = it[1];    // in the adj right now!!
            
            adj[u].push_back(v);
        }
        // indegree (anti of adj list)
        vector<int> indegree(V,0);
        for(int i=0; i<V; i++){
            for(auto it: adj[i]){
                indegree[it]++;   // jitni baar we find an element in adj that means utni nodes ussme aa rhi h
            }
        }
        
        queue<int> q;
        for(int i=0; i<V; i++){
            if(indegree[i]==0){
                q.push(i);    // push the orphanns 
            }
        }
        
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);    // push the node if ab uske saare baap are in queue
                }
            }
            
        }
        return ans;
        
    }
};