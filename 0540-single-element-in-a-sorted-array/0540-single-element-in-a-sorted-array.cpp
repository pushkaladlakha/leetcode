class Solution {
public:
    int check(int i , vector<int> &nums){
        if(i>0){if(nums[i-1]==nums[i]) return -1;}
        if(i<nums.size()-1){if(nums[i+1]==nums[i]) return 1;}
        return 0;
    }
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(mid%2==0){
                if(check(mid,nums)==-1){
                    high=mid-1;
                }
                else if(check(mid,nums)==1){
                    low=mid+1;
                }
                else return nums[mid];
            }
            else{
                if(check(mid,nums)==-1){
                    low=mid+1;
                }
                else if(check(mid,nums)==1){
                    high=mid-1;
                }
                else return nums[mid];
            }
        }
        return -1;
    }
};