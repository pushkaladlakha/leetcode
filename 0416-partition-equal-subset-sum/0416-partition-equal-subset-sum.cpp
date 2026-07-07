class Solution {
public:
    bool rec(int index , int target , vector<int> &nums,vector<vector<int>> &dp){
        if(nums[index]==target){return true;}
        else if(index<=0) return false;
        if(dp[index][target]!=-1) return bool(dp[index][target]);
        bool take = false;
        if(target>=nums[index]) take = rec(index-1,target-nums[index],nums,dp);
        bool leave = rec(index-1,target,nums,dp);
        return dp[index][target]=take||leave;
    }
    bool canPartition(vector<int>& nums) {
        int sum {};
        for(auto i : nums){sum+=i;}
        if(sum%2) return false;
        vector<vector<int>> dp(nums.size(),vector<int>(sum/2+1,-1));
        return rec(nums.size()-1,sum/2,nums,dp);
    }
};