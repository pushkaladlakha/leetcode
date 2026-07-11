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
    vector<vector<int>> threeSum(vector<int>& nums) {
        ///-4 -1 -1 0 1 2
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int left = 0; left<nums.size() ; skipr(left,nums)){
            int middle = left+1;
            int right = nums.size()-1;
            while(left<right && middle<right){
                if(nums[left]+nums[right]+nums[middle]==0){
                    ans.push_back({nums[left],nums[middle],nums[right]});
                    skipr(middle,nums);
                    skipl(right,nums);
                }
                else if(nums[left]+nums[right]+nums[middle]<0){
                    skipr(middle,nums);
                }
                else{
                    skipl(right,nums);
                }
            }
        }
        return ans;
    }
};