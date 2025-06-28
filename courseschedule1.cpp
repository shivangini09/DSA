class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        int V = numCourses;
        for(auto it: prerequisites){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }
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
        if(ans.size()==V){
            return true;
        }
        else{
            return false;
        }
    }
};