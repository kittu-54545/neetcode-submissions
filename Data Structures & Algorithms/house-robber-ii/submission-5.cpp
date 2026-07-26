class Solution {
public:
    int rob(vector<int>& nums) {
        // tabulation bottom up
        int n = nums.size(), ans = 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        vector<int> dp(n + 1, -1);
        dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n - 1; i++) {
            int take = nums[i] + dp[i-2];
            int notake = dp[i-1];
            dp[i] = max(take, notake);
        }
        ans = max(ans, dp[n-2]);
        // circular so pass a end varaible which determine till where we can go
        dp.clear();
        dp.resize(n+1, -1);
        dp[1] = nums[1], dp[2] = max(nums[1], nums[2]);
        for (int i = 3; i < n; i++) {
            int take = nums[i] + dp[i-2];
            int notake = dp[i-1];
            dp[i] = max(take, notake);
        }
        ans = max(ans, dp[n-1]);
        return ans;
    }
};
