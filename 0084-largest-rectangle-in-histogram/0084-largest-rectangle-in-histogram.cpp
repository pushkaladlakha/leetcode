class Solution {
public:
    vector<int> nse(vector<int> &nums){
        stack<int> st;vector<int> ans(nums.size(),nums.size());
        for(int i = nums.size()-1 ;i>-1 ; i--){ 
            while(!st.empty()){
                if(nums[st.top()]>=nums[i]){st.pop();}
                else{
                    ans[i]=st.top();
                    st.push(i);
                    break;
                }
            }
            if(st.empty()){st.push(i);continue;}
            
        }
        return ans;
    }
    vector<int> pse(vector<int> &nums){
        stack<int> st;vector<int> ans(nums.size(),-1);
        for(int i = 0 ;i<nums.size() ; i++){ 
            while(!st.empty()){
                if(nums[st.top()]>=nums[i]){st.pop();}
                else{
                    ans[i]=st.top();
                    st.push(i);
                    break;
                }
            }
            if(st.empty()){st.push(i);continue;}
            
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int maxi = 0;
        vector<int> v1 = pse(heights);
        vector<int> v2 = nse(heights);
        for(int i = 0 ; i<heights.size() ;i++){
            maxi=max(maxi,(v2[i]-v1[i]-1)*heights[i]);
        }
        return maxi;          
    }
};