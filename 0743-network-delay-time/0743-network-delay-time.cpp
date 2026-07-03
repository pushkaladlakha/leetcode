class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q1;
        vector<int> time(n + 1, INT_MAX);
        time[0]=0;
        for(auto it : times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        //starting from k
        q1.push({0,k});time[k]=0;

        while(!q1.empty()){
            int data = q1.top().second;
            int d = q1.top().first;
            q1.pop();
            if(d>time[data]) continue;
            for(auto it : adj[data]){
                if(d+it.second<time[it.first]){
                    time[it.first]=d+it.second;
                    q1.push({d+it.second,it.first});
                }
            }
        }
        int max = 0 ;
        for(auto it : time){
            if(it==INT_MAX) return -1;
            else if(it>max) max=it;
        }
        return max;
        


    }
};