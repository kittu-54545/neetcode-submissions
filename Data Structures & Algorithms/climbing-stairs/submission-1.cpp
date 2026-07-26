class Solution {
public:
    int hel(int i, vector<int> &dp) {
        if (i <= 2) return i;
        if (dp[i] != -1) return dp[i];
        int one = hel(i-1, dp);
        int two = hel(i-2, dp);
        return dp[i] = one + two;
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return hel(n, dp);
    }
};
