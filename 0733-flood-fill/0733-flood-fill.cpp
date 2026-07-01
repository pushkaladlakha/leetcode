class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int og=image[sr][sc];
        image[sr][sc]=color;
        queue<pair<int,int>> q;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        q.push({sr,sc});
        int s1=image.size();
        int s2=image[0].size();
        int vis[image.size()][image[0].size()];memset(vis,0,sizeof(vis));
        while(!q.empty()){
            for(int i = 0 ; i<4 ; i++){
                int row = q.front().first+drow[i];
                int col = q.front().second+dcol[i];
                if(row>=0 && col>=0 && row<s1 && col<s2 && vis[row][col]!=1 && image[row][col]==og){
                    vis[row][col]=1;
                    image[row][col]=color;
                    q.push({row,col});
                }
            }
            q.pop();
        }
        return image;
    }
};