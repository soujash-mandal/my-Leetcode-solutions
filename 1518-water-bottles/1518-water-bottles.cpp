class Solution {
public:
    int numWaterBottles(int n, int e) {
        int res=0;
        int extra=0;
        while(n)
        {
            res+=n;
            extra+=n;            
            n=extra/e;
            extra=extra%e;
        }
        return res;
    }
};