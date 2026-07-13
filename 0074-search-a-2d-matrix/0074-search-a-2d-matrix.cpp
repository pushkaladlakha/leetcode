class Solution {
public:
    bool bs (vector<int> &nums , int target){
        int low = 0 ;
        int high = nums.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target) return true;
            else if (nums[mid]<target) low=mid+1;
            else high =mid-1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low1 = 0;
        int high1 = matrix.size()-1;
        while(low1<=high1){
            int mid1= (low1+high1)/2;
            if(target>=matrix[mid1][0] && target<=matrix[mid1][matrix[0].size()-1]){
                return bs(matrix[mid1],target);
            }
            else if(target<matrix[mid1][0]){
                high1=mid1-1;
            }
            else low1=mid1+1;
        }
        return false;
    }
};