class Solution {
public:
    int rec(int index ,int buy , int tran,vector<int> &prices , vector<vector<vector<int>>> &dp){
        if(index>prices.size()-1) return 0;
        if(tran>2) return 0;
        if(dp[index][buy][tran]!=-1) return dp[index][buy][tran];
        int profit = 0;
        if(buy){
            profit=max(rec(index+1,0,tran+1,prices,dp)-prices[index],rec(index+1,1,tran,prices,dp));
        }
        else{
            profit=max(prices[index]+rec(index+1,1,tran,prices,dp),rec(index+1,0,tran,prices,dp));
        }

        return dp[index][buy][tran]=profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        return rec(0,1,0,prices,dp);
    }
};