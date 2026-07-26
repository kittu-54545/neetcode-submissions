class Solution {
public:
    int minCostClimbingStairs(vector<int>& nums) {
        // space optimization
        int n = nums.size();
        if (n < 2) return min(nums[0], nums[1]);
        vector<int> dp(n + 1, -1);
        int pre1 = nums[0], pre2 = nums[1], ans;
        for (int i = 2; i < n; i++) {
            ans = nums[i] + min(pre1, pre2);
            pre1 = pre2;
            pre2 = ans;
        }
        return min(pre2, pre1);
    }
};
