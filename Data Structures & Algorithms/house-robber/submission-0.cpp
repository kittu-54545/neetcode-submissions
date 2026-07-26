class Solution {
public:
    int hel(int i, vector<int> &nums, vector<int> &dp) {
        if (i < 0) return 0;
        if (i == 0) return nums[i];
        if (i == 1) return max(nums[0], nums[1]);
        if (dp[i] != -1) return dp[i];
        int take = nums[i] + hel(i-2, nums, dp);
        int notake = hel(i-1, nums, dp);
        return dp[i] = max(take, notake);
    }
    int rob(vector<int>& nums) {
        // memo + top bottom
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return hel(n - 1, nums, dp);
    }
};
