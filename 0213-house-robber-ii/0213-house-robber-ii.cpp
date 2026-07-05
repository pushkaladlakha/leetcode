class Solution {
public:
    int f(vector<int> &num){
        int prev2 = 0;
        int prev = num[0];
        for(int i = 1 ; i<num.size() ; i++){
            int take = num[i];
            if(i>1) take += prev2;
            int skip = prev;
            int curr = max(take,skip);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){return nums[0];}
        vector<int> l1;
        vector<int> l2;
        for(int i = 0 ; i<nums.size() ; i++){
            if(i!=0) l1.push_back(nums[i]);
            if(i!=nums.size()-1) l2.push_back(nums[i]);
        }

    return max(f(l1),f(l2));
    }

};