class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0;
        int cnt2 = 0;
        int el1 = INT_MIN;
        int el2 = INT_MIN;
        for(auto i : nums){
            if(cnt1==0 && i!=el2){
                cnt1++;
                el1 = i;
            }
            else if(cnt2==0 && i!=el1){
                cnt2++;
                el2=i;
            }
            else if(i==el1){cnt1++;}
            else if(i==el2){cnt2++;}
            else{cnt1--;cnt2--;}
        }
        cnt1=0;cnt2=0;vector<int> arr;
        for(auto i : nums){
            if(i==el1){cnt1++;}
            else if(i==el2){cnt2++;}
        }
        int n = 0;
        n=(nums.size()/3)+1;
        if(cnt1>=n){arr.push_back(el1);}
        if (cnt2>=n){arr.push_back(el2);}
        return arr;

    }
};