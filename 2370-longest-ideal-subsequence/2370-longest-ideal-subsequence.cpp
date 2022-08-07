class Solution {
public:
    int longestIdealString(string s, int k) {
        int dp[150] = {}, res = 0;
        for (auto& i : s) {
            int cur = 0;
            for (int j = i - k; j <= i + k; ++j)
                cur = max(cur, dp[j] + 1);
            res = max(res, dp[i] = cur);
        }
        return res;
    }
};