class Solution {
private:
    int m, n;
    vector<int> dir = {-1, 0, 1, 0, -1};
    vector<vector<bool>> vi;
    void bfs(int i, int j, vector<vector<int>>& nums, int &curr) {
        queue<pair<int, int>> q;
        q.push({i, j});
        vi[i][j] = 1;
        while (q.size()) {
            auto tp = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int dx = tp.first + dir[d], dy = tp.second + dir[d + 1];
                if (dx < 0 or dx >= m or dy < 0 or dy >= n or nums[dx][dy] == 0 or vi[dx][dy]) continue;
                q.push({dx, dy});
                vi[dx][dy] = 1;
                curr++;
            }
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& nums) {
        m = nums.size(), n = size(nums[0]);
        int ans = 0, curr = 0;
        vi.resize(m, vector<bool>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (nums[i][j] and !vi[i][j]) {
                    curr = 1;
                    bfs(i, j, nums, curr);
                }
                ans = max(curr, ans);
            }
        }
        return ans;
    }
};
