class Solution {
public:
    int hel(int i, int e, vector<int> &nums, vector<int> &dp) {
        if (i < e) return 0;
        if (i == e) return nums[i];
        if (dp[i] != -1) return dp[i];
        int take = nums[i] + hel(i-2, e, nums, dp);
        int notake = hel(i-1, e, nums, dp);
        return dp[i] = max(take, notake);
    }
    int rob(vector<int>& nums) {
        // memo + top bottom
        int n = nums.size();
        if (n == 1) return nums[0];
        
        vector<int> dp(n + 1, -1);
        // circular so pass a end varaible which determine till where we can go
        int last = hel(n - 1, 1, nums, dp);
        dp.clear();
        dp.resize(n+1, -1);
        int secondl = hel(n - 2, 0, nums, dp);
        return max(last, secondl);
    }
};
