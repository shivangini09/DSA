class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // we will use bfs
        int v = adj.size(); //size of graph
        vector<int> distance(v,INT_MAX);
        // vector<int> vis(v,0);
        queue<pair<int,int>> q;
        q.push({src,0});
        distance[src]=0;
        // vis[0]=1;
        while(!q.empty()){
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();
            
            // once popped out let's move to adj
            for(auto it: adj[node]){
                if(dist+1<distance[it]){
                    distance[it]=dist+1;   // update the distance!.!.!
                    q.push({it,distance[it]});
                }
                
            }
            
        }
        vector<int> ans;
        for(int i=0;i<v;i++){
            if(distance[i]!=INT_MAX){
                ans.push_back(distance[i]);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
        
    }
};