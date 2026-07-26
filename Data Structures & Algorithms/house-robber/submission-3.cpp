class Solution {
public:
    int rob(vector<int>& nums) {
        // space optimization
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        int pre1 = nums[0], pre2 = max(nums[0], nums[1]), ans;
        for (int i = 2; i < n; i++) {
            int take = nums[i] + pre1;
            int notake = pre2;
            ans = max(take, notake);
            pre1 = pre2;
            pre2 = ans;
        }
        return ans;
    }
};
