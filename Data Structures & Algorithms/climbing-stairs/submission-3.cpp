class Solution {
public:
    int climbStairs(int n) {
        // space optimization
        if (n <= 2) return n;
        int pre1 = 1, pre2 = 2, ans;
        for (int i = 3; i <= n; i++) {
            ans = pre1 + pre2;
            pre1 = pre2;
            pre2 = ans;
        }
        return ans;
    }
};
