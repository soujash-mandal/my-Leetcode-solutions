class Solution {
public:
    bool isPowerOfFour(int n) {
        int x=n;
        while(x)
        {
            if(x%4) break;
            x/=4;
        }
        
        if(x==1) return true;
        return false;
    }
};