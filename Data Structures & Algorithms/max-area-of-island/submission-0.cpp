class Solution {
private:
    int m, n;
    vector<int> dir = {-1, 0, 1, 0, -1};
    vector<vector<bool>> vi;
    void dfs(int i, int j, vector<vector<int>>& nums, int &curr) {
        vi[i][j] = 1;
        if (i < 0 or i >= m or j < 0 or j >= n) return;
        for (int d = 0; d < 4; d++) {
            int dx = i + dir[d], dy = j + dir[d + 1];
            if (dx < 0 or dx >= m or dy < 0 or dy >= n or nums[dx][dy] == 0 or vi[dx][dy]) continue;
            dfs(dx, dy, nums, ++curr);
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& nums) {
        m = nums.size(), n = size(nums[0]);
        int ans = 0, curr = 0;
        vi.resize(m, vector<bool>(n, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (nums[i][j] and !vi[i][j]) {
                    curr = 1;
                    dfs(i, j, nums, curr);
                }
                ans = max(curr, ans);
            }
        }
        return ans;
    }
};
