class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        queue<int> q1;
        for(auto it : prerequisites){
            indegree[it[0]]++;
            adj[it[1]].push_back(it[0]);
        }
        for(int i = 0 ; i< numCourses ; i++){
            if(indegree[i]==0){
                q1.push(i);
            }
        }
        int cnt = 0 ;
        while(!q1.empty()){
            cnt++;
            for(auto it: adj[q1.front()]){

                if(--indegree[it]==0){
                    q1.push(it);

                }
            }
            q1.pop();
        }
        if(cnt==numCourses){
            return true;
        }
        return false;
    }
};