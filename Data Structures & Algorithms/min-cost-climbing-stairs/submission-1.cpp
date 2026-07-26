class Solution {
public:
    int minCostClimbingStairs(vector<int>& nums) {
        // tabulation bottom up
        int n = nums.size();
        if (n < 2) return min(nums[0], nums[1]);
        vector<int> dp(n + 1, -1);
        dp[0] = nums[0], dp[1] = nums[1];
        for (int i = 2; i < n; i++) {
            dp[i] = nums[i] + min(dp[i-1], dp[i-2]);
        }
        return min(dp[n-1], dp[n-2]);
    }
};
