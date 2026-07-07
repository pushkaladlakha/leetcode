class Solution {
public:
    int rec(int index , int target , vector<int> &nums , vector<vector<long long>> &dp){
        if(target==0) return 1;
        if(index<0) return 0;
        if(dp[index][target]!=-1) return dp[index][target];
        int pick = 0;
        if(nums[index]<=target) pick = rec(index,target-nums[index],nums,dp);
        int leave = rec(index-1,target,nums,dp);

        return dp[index][target]=pick+leave;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<long long>> dp(coins.size(),vector<long long>(amount+1,-1));
        return rec(coins.size()-1,amount,coins,dp);
    }
};