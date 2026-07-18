class Solution {
public:
    int f(int start , int end , vector<int> &nums , vector<vector<int>> &dp){
        if(start>end) return 0;
        if(dp[start][end]!=-1) return dp[start][end];
        int mini = INT_MAX;
        for(int index = start ; index<=end ; index++){
            int cost = nums[end+1]-nums[start-1] + f(start,index-1,nums,dp) + f(index+1,end,nums,dp);
            mini = min(mini,cost);
        }
        return dp[start][end]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        vector<vector<int>> dp(cuts.size()+2,vector<int>(cuts.size()+2,-1));
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        return f(1,cuts.size()-2,cuts,dp);
    }
};