class Solution {
public: 
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
        visited[node] = 1;
        for(int neighbor : adj[node]) {
            if(!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<vector<int>> adj(V);
        
        // Convert adjacency matrix to adjacency list
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int count = 0;
        vector<int> vis(V, 0);

        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(i, adj, vis);
                count++;
            }
        }
        
        return count;
    }
};