class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        vector<vector<int>> adj(graph.size());
        queue<int> q;
        vector<int> indegree(graph.size());
        for(int i {0} ; i<graph.size();i++){
            for(auto it : graph[i]){
                adj[it].push_back(i);
                indegree[i]++;
            }
        }
        for(int i =0; i<graph.size(); i++){
            if(indegree[i]==0){q.push(i);ans.push_back(i);}
        }
        while(!q.empty()){
            for(auto it : adj[q.front()]){
                if(--indegree[it]==0){
                    q.push(it);
                    ans.push_back(it);
                }
            }
            q.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;

    }
};