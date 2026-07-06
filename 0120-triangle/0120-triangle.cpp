class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        vector<int> temp;
        vector<int> dp;
        for(int i = 0 ; i<n ; i++){
            dp.push_back(0);
            for(int j = 0 ; j<i+1 ; j++){
                if(i==0 && j==0){dp[0]=triangle[0][0];continue;}
                int up{INT_MAX} ; int diag{INT_MAX};
                if(i>0 && j<i) up = dp[j]+triangle[i][j];
                if(i>0 && j>0) diag = temp[j-1]+triangle[i][j];
                dp[j]=min(up,diag);
            }
            temp=dp;
        }
        int min1=INT_MAX;
        for(auto i : dp){
            min1=min(min1,i);
        }
        return min1;
    }
};