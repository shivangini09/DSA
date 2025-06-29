class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adjrev(n);
        vector<int> indegree(n,0);
        for(int i=0; i<n; i++){
            for(auto it: graph[i]){
                adjrev[it].push_back(i);    // reverse adjacency list taiyaar
                indegree[i]++; // jitne padosi tk jaa rhe the ab vo aa rhe h
            }
        }
        queue<int> q;
        vector<int> safenodes;


        // push all terminal nodes in the queue first!
        for(int i=0; i<n; i++){
            if(indegree[i]==0){
                q.push(i);   
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            safenodes.push_back(node);

            for(auto it: adjrev[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);     // push if it also is free now!
                }
            }
        }
        sort(safenodes.begin(),safenodes.end());
        return safenodes;
        
    }
};