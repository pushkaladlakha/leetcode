class Solution {
public:
    void gapsort(int gap , vector<int> &nums){
        while(gap){
            int left = 0;
            int right = gap;
            while(right<nums.size()){
                if(nums[left]>nums[right]){swap(nums[left],nums[right]);}
                left++;right++;
            }
            if(gap==1) break;
            gap=ceil((double)gap/2);
        }
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int point = m;int j = 0;
        while(point<nums1.size()){
            nums1[point]=nums2[j];
            point++;j++;
        }
        gapsort(n+m,nums1);
    }
};