class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)
            return false;
        if((n&(n-1))==0)
        {
            int check=log(n)/log(2);
            if(check%2==0)
                return true;
        }
        return false;
    }
};