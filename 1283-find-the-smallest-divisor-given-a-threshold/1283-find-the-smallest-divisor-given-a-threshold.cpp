class Solution {
public:
    int f(int i , vector<int> &nums){
        int sum = 0;
        for(auto n : nums){
            sum+=ceil((double)n/i);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(auto i : nums){
            mini=min(mini,i);
            maxi=max(maxi,i);
        }
        int low = 1;
        int high = maxi;
        while(low<=high){
            int mid = (low+high)/2;
            if(f(mid,nums)>threshold){
                low=mid+1;
            }
            else high = mid-1;
        }
        return low;
    }
};