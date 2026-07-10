class Solution {
public:
    int ncr(int n , int r){
        if(n==0 || r==0 || n==r) return 1;
        long ans = 1;int div = 1;
        for(int i = n ; i>n-r ;i--){
            ans=ans*i/div;
            div++;
        }
        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vec;
        for(int i = 0 ; i<numRows ;i++){
            vector<int> temp_ans;
            for(int j = 0 ;j<i+1 ;j++){
                temp_ans.push_back(ncr(i,j));
            }
            vec.push_back(temp_ans);
        }
        return vec;
    }
};