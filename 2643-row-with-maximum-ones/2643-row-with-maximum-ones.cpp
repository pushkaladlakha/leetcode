class Solution {
public:
    int f(vector<int> nums){
        int sum=0;
        for(auto i : nums){sum+=i;}
        return sum;
    }
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxi = 0;int ind = 0;
        for(int i = 0 ; i<mat.size() ; i++){
            if(f(mat[i])>maxi) ind =i;
            maxi=max(maxi,f(mat[i]));
        }
        return {ind,f(mat[ind])};
    }
};