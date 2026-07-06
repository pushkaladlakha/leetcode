class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dp(m,0);
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(i==0 && j==0){dp[0]=grid[0][0];continue;}
                int up{INT_MAX} ; int left{INT_MAX};
                if(i>0) up = dp[j]+grid[i][j];
                if(j>0) left = dp[j-1]+grid[i][j];
                dp[j]=min(up,left);
            }
        }
        return dp[m-1];
    }
};