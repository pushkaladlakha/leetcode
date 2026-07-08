class Solution {
public:
    int rec(int index ,int buy , int tran,vector<int> &prices , vector<vector<vector<int>>> &dp,int k){
        if(index>prices.size()-1) return 0;
        if(tran>k) return 0;
        if(dp[index][buy][tran]!=-1) return dp[index][buy][tran];
        int profit = 0;
        if(buy){
            profit=max(rec(index+1,0,tran+1,prices,dp,k)-prices[index],rec(index+1,1,tran,prices,dp,k));
        }
        else{
            profit=max(prices[index]+rec(index+1,1,tran,prices,dp,k),rec(index+1,0,tran,prices,dp,k));
        }

        return dp[index][buy][tran]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));
        return rec(0,1,0,prices,dp,k);
    }
};