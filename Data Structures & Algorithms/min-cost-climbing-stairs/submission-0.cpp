class Solution {
public:
    int hel(int i, vector<int> &nums, vector<int> &dp) {
        if (i < 0) return 0;
        if (i < 2) return nums[i];
        if (dp[i] != -1) return dp[i];
        int one = hel(i-1, nums, dp);
        int two = hel(i-2, nums, dp);
        return dp[i] = nums[i] + min(one, two);
    }
    int minCostClimbingStairs(vector<int>& nums) {
        // memo + top bottom
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        int last = hel(n - 1, nums, dp);
        int secondlast = hel(n - 2, nums, dp);
        return min(last, secondlast);
    }
};
