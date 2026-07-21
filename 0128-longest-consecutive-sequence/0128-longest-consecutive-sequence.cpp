class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> mp;int max1=0;int prev;int temp_len=0;
        for(int i : nums){mp[i]++;}
        int count=0;
        
        for(auto it: mp){
            if(count==0){
                prev=it.first;
                temp_len=1;
                count++;
            }
            if(it.first==prev+1){
                prev=it.first;
                temp_len++;
            }
            else{
                max1=max(temp_len,max1);
                prev=it.first;
                temp_len=1;
            }
        }
        max1=max(temp_len,max1);
        return max1;
    }
};