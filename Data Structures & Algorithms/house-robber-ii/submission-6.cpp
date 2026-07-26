class Solution {
public:
    int rob(vector<int>& nums) {
        // space optimization
        int n = nums.size(), ans = 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        int pre1 = nums[0], pre2 = max(nums[0], nums[1]), curr = 0;
        for (int i = 2; i < n - 1; i++) {
            int take = nums[i] + pre1;
            int notake = pre2;
            curr = max(take, notake);
            pre1= pre2;
            pre2 = curr;
        }
        ans = max(ans, pre2);
        
        // circular so pass a end varaible which determine till where we can go
        pre1 = nums[1], pre2 = max(nums[1], nums[2]), curr = 0;
        for (int i = 3; i < n; i++) {
            int take = nums[i] + pre1;
            int notake = pre2;
            curr = max(take, notake);
            pre1= pre2;
            pre2 = curr;
        }
        ans = max(ans, pre2);
        return ans;
    }
};
