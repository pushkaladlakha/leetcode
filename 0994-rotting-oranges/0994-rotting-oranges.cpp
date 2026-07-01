class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q1;int cnt=0;
        for(int i =0 ; i<grid.size() ; i++){
            for(int j=0 ; j<grid[0].size() ; j++){
                if(grid[i][j]==2){
                    q1.push({{i,j},0});
                }
                else if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        int drow[] = {0,1,0,-1};
        int dcol[] = {1,0,-1,0};
        bool swap=true;
        int tm = 0;
        while(!q1.empty()){
            for(int i = 0 ; i<4 ; i++){
                int row = q1.front().first.first+drow[i];
                int col = q1.front().first.second+dcol[i];
                int t=q1.front().second;
                tm=max(tm,t);
                if(row>=0 && col>=0 && row<grid.size() && col<grid[0].size() && grid[row][col]==1){
                    q1.push({{row,col},t+1});
                    grid[row][col]=2;
                    --cnt;
                }
            }
            q1.pop();
        }

        if(cnt){
            return -1;
        }
        else return tm;
    }
};