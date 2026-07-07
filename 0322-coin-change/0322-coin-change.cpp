class Solution {
public:
    int rec(int index , int target , vector<int> &nums , vector<vector<int>> &dp){
        if(index<0){return 1e8;}
        else if(target==0) return 0;
        if(dp[index][target]!=-1) return dp[index][target];
        int take {INT_MAX};
        if(nums[index]<=target) take = 1+ rec(index,target-nums[index],nums,dp);
        int leave = rec(index-1,target,nums,dp);
        return dp[index][target]=min(leave,take);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        if(rec(coins.size()-1,amount,coins,dp)>=1e8) return -1;
        return rec(coins.size()-1,amount,coins,dp);

    }
};