class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reach=0;
        for(int i = 0 ; i<nums.size() ; i++){
            if(i>max_reach){return false;}
            max_reach=max(i+nums[i],max_reach);
        }
        return true;
    }
};