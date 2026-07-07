class Solution {
public:
    int rec(int index , int target , vector<int> &nums){
        if(index<0 && target==0) return 1;
        else if (index<0) return 0;
        ///if(dp[index][target]!=-1) return dp[index][target];
        int pick = 0 ;
        if(nums[index]<=target) pick = rec(index-1,target-nums[index],nums);
        int leave = rec(index-1,target,nums);
        return pick+leave;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = target;
        for (auto i : nums){sum+=i;}
        if(sum%2) return 0;
        sum=sum/2;
        ///vector<vector<int>> dp(nums.size(),vector<int>(sum+1,-1));
        return rec(nums.size()-1,sum,nums);
    }
};