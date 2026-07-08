class Solution {
public:
    int rec(int index , int last_i , vector<int> &nums , vector<vector<int>> &dp){
        if(index>nums.size()-1) return 0;
        if(dp[index][last_i+1]!=-1) return dp[index][last_i+1];
        int take = INT_MIN;
        if(last_i==-1||nums[index]>nums[last_i]) take = 1 + rec(index+1,index,nums,dp);
        int leave = rec(index+1,last_i,nums,dp);
        return dp[index][last_i+1] = max(take,leave);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,-1));
        return rec(0,-1,nums,dp);
    }
};