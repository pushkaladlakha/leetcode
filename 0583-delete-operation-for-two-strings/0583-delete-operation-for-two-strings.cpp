class Solution {
public:
    int rec(int p1 , int p2 , string &t1 , string &t2,vector<vector<int>> &dp){
        if(p1>t1.size()-1) return 0;
        if(p2>t2.size()-1) return 0;
        else if(t1[p1]==t2[p2]){
            return dp[p1][p2]=1+rec(p1+1,p2+1,t1,t2,dp);
        };
        if(dp[p1][p2]!=-1) return dp[p1][p2];

        int left = rec(p1+1,p2,t1,t2,dp);
        int right = rec(p1,p2+1,t1,t2,dp);

        return dp[p1][p2]=max(left,right);
    }
    int minDistance(string word1, string word2) {
        string s2;vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),-1));
        
        int ans = rec(0 , 0 ,word1,word2,dp);
        return (word1.size()+word2.size()-2*ans);

    }
};