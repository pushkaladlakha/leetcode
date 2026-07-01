class Solution {
public:
    void dfs(int city , vector<vector<int>> & isConnected , vector<int> &vis){
        vis[city]=1;
        for(int next = 0 ; next<isConnected.size() ; next++){
            if(isConnected[city][next] && !vis[next] ){
                dfs(next,isConnected,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> vis(isConnected.size(),0);int ans = 0;
        for(int i = 0 ; i< isConnected.size() ; i++){
            if(!vis[i]){
                ans++;
                dfs(i,isConnected,vis);
            }
        }
        return ans;
    }
};