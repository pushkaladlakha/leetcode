class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int c = 0;
        int drow[] = {0,1,0,-1};
        int dcol[] = {-1,0,1,0};
        queue<pair<int,int>> q;
        for(int i = 0 ;i<grid.size() ; i++){
            for(int j = 0 ; j<grid[0].size();j++){
                if(grid[i][j]==1){
                    if(i==0||j==0||i==grid.size()-1||j==grid[0].size()-1){q.push({i,j});grid[i][j]=0;}
                    else{
                        c++;
                    }
                }
            }
        }
        while(!q.empty()){
            for(int i = 0 ;i<4 ; i++){
                int row = q.front().first+drow[i];
                int col = q.front().second+dcol[i];
                if(row>=0 && col>=0 && row<grid.size() && col<grid[0].size() && grid[row][col]==1){
                    c--;
                    q.push({row,col});
                    grid[row][col]=0;
                }
            }
            q.pop();
        }
        return (c>0) ? c:0;
    }
};