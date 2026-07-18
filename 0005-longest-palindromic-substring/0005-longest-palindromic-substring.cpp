class Solution {
public:
    string longestPalindrome(string s) {
        string str;int max_len = 0;
        int l = 0 ; int r = 0;
        for(int i = 0 ; i<s.size() ; i++){
            l = i ; r = i;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                if(r-l+1>max_len){
                    str = s.substr(l, r - l + 1);
                    max_len=r-l+1;
                }
                l--;r++;
            }
        }
         l = 0 ;  r = 0;
        for(int i = 0 ; i<s.size() ; i++){
            l = i ; r = i+1;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                if(r-l+1>max_len){
                    str = s.substr(l, r - l + 1);
                    max_len=r-l+1;
                }
                l--;r++;
            }
        }


        if(str.size()==0){str=s[0];}

        return str;
    }
};