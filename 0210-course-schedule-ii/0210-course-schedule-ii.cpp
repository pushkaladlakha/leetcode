class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);vector<int> arr;
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
            arr.push_back(q1.front());
            for(auto it: adj[q1.front()]){

                if(--indegree[it]==0){
                    q1.push(it);

                }
            }
            q1.pop();
        }
        if(cnt==numCourses){
            return arr;
        }
        return {};
    }
};
/// kisi ki indegree == 0 not at all to loop mai fasa hua hai