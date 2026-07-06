class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<int> dp(m,0);
        vector<int> temp(m,0);
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(obstacleGrid[i][j]==1)continue;
                if(i==0 && j==0){dp[0]=1;continue;}
                int up{0} ; int left{0};
                if(i>0) up = temp[j];
                if(j>0) left = dp[j-1];
                dp[j]=up+left;
            }
            temp=dp;
            fill(dp.begin(),dp.end(),0);
        }
        return temp[m-1];
    }
};