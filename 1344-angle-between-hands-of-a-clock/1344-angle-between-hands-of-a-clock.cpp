class Solution {
public:
    double angleClock(int h, int m) {
        double x=6*m;
        double y=30*h+double((double)m/2);
        double res= abs(x-y);
        
        return min(res,360-res);
    }
};