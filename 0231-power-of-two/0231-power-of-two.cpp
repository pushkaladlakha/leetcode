class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0) return false;
        long long n1=n*1LL;
        n=abs(n1);
        if((n1 & n1-1)==0) return true;
        return false;
    }
};