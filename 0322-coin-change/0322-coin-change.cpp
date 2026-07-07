class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,1e8));
        for(int i = 0 ; i < coins.size() ; i++){
            for(int j = 0 ; j< amount+1 ; j++){
                if(j==0){dp[i][j]=0;continue;}
                if(i==0){
                    if(j%coins[0]==0) dp[0][j]=j/coins[0];
                    continue;
                }
                int take {INT_MAX};
                if(coins[i]<=j) take = 1+ dp[i][j-coins[i]];
                int leave = dp[i-1][j];
                dp[i][j]=min(take,leave);
            }
        }
        if(dp[coins.size()-1][amount]>=1e8) return -1;
        return dp[coins.size()-1][amount];
    }
};