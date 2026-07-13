class Solution {
public:
    int no_b(int day , vector<int> &nums , int k){
        int sum = 0 ; int boq = 0;
        for(auto i : nums){
            if(i<=day){
                sum++;
                boq += sum/k;
                sum=sum%k;
            }
            else{
                sum=0;
            }
        }
        return boq;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        if(1LL*m*k>bloomDay.size()) return -1;
        for(auto i : bloomDay){
            mini=min(i,mini);
            maxi=max(i,maxi);
        }
        int low = mini;
        int high = maxi;
        while(low<=high){
            int mid = (low+high)/2;
            if(no_b(mid,bloomDay,k)<m){
                low=mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low ;
    }
};