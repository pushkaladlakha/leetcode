class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;
        int drow[]={0,0,1,-1,1,-1,1,-1};
        int dcol[]={1,-1,0,0,1,1,-1,-1};
        vector<vector<int>> arr(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        priority_queue<
    pair<int, pair<int,int>>,
    vector<pair<int, pair<int,int>>>,
    greater<pair<int, pair<int,int>>>
> q;
        arr[0][0]=0;
        q.push({0,{0,0}});
        while(!q.empty()){
            int x = q.top().second.first;
            int y = q.top().second.second;
            int dis = q.top().first;
            dis++;
            q.pop();
            for(int i {0} ; i<8 ; i++){
                int col = y+dcol[i];
                int row = x+drow[i];
                if(row>=0 && col>=0 && col<grid[0].size() && row<grid.size() && grid[row][col]==0){
                    if(arr[row][col]>dis){
                        arr[row][col]=dis;
                        q.push({dis,{row,col}});
                    }
                }
            }
            
        }
        return (arr[grid.size()-1][grid[0].size()-1]==INT_MAX) ? -1 : arr[grid.size()-1][grid[0].size()-1]+1;
    }
};