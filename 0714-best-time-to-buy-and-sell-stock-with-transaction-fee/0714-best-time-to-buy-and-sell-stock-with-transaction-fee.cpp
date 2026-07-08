class Solution {
public:
    int rec(int index ,int buy ,vector<int> &prices ,vector<vector<int>> &dp,int fee){
        if(index>prices.size()-1) return 0;
        if(dp[index][buy]!=-1) return dp[index][buy];
        int profit = 0;
        if(buy){
            profit=max(rec(index+1,0,prices,dp,fee)-prices[index],rec(index+1,1,prices,dp,fee));
        }
        else{
            profit=max(prices[index]+rec(index+1,1,prices,dp,fee)-fee,rec(index+1,0,prices,dp,fee));
        }
        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return rec(0,1,prices,dp,fee);
    }
};