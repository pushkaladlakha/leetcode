class Solution {
public:
    int max_mon(int index , vector<int> &nums,vector<int> &dp){
        if(index>=nums.size()-2){return nums[index];}
        if(dp[index]!=-1){return dp[index];}
        int small = max_mon(index+2,nums,dp) + nums[index];int big = 0;
        if(index<=nums.size()-4) big=max_mon(index+3,nums,dp)+nums[index];
        dp[index]=max(small,big);
        return max(small,big);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        if(nums.size()<3){
            if(nums.size()==1){return nums[0];}
            else return max(nums[0],nums[1]);
        }
        return max(max_mon(0,nums,dp),max_mon(1,nums,dp));
    }
};