// User function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        // Step 1: Build adjacency list
        vector<vector<pair<int, int>>> adj(V);
        
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt}); // Undirected Graph
        }
        
        // Step 2: Min-Heap Priority Queue {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        pq.push({0, src});
        
        // Step 3: Dijkstra's Algorithm
        while(!pq.empty()){
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                int edgeWeight = it.second;
                
                if(distance + edgeWeight < dist[adjNode]){
                    dist[adjNode] = distance + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        
        return dist;
    }
};