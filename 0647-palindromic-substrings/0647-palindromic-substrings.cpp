class Solution {
public:
    int countSubstrings(string s) {
        int sum = 0;
        /// odd palindrom length
        for(int i = 0 ; i<s.size() ; i++){
            int left = i ; int right = i ;
            while(left>=0 && right<s.size() && s[left]==s[right]){
                sum++;
                left--;right++;
            }
        }
        for(int i = 0 ; i<s.size() ; i++){
            int left = i -1 ; int right =i;
            while(left>=0 && right<s.size() && s[left]==s[right]){
                sum++;
                left--;right++;
            }
        }
        return sum;
    }
};