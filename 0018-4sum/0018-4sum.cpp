class Solution {
public:
    void skipr(int &i , vector<int> &nums){
        i++;
        while(i<nums.size() && nums[i]==nums[i-1]){i++;}
    }
    void skipl(int &i , vector<int> &nums){
        i--;
        while(i>0 && nums[i]==nums[i+1]){i--;}
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        ///-2 -1 1 0 0 2
        for(int i = 0 ; i<nums.size() ; skipr(i,nums)){
            for(int j = i+1 ; j<nums.size() ; skipr(j,nums)){
                int k = j+1;
                int l = nums.size()-1;
                while(k<l){
                    long sum = 1LL*nums[i]+nums[j]+nums[k]+nums[l];
                    if(sum<target){
                        skipr(k,nums);
                    }
                    else if (sum>target){
                        skipl(l,nums);
                    }
                    else{
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        skipr(k,nums);
                        skipl(l,nums);
                    }
                }
            }
        }
        return ans;
    }
};