class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> res;
        if(num%3==0)
        {
            res={num/3-1,num/3,num/3+1};
        }
        
        return res;
    }
};