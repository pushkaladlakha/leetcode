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
    int longestPalindromeSubseq(string s) {
        string s2 ;
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
        for(int i = s.size()-1 ; i>-1 ; i--){
            s2+=s[i];
        }
        return rec(0,0,s,s2,dp);
    }
};