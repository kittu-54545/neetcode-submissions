class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> q;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for (int i: nums) q.push(i);
        while (q.size() > K) q.pop();
    }
    int add(int val) {
        q.push(val);
        while (q.size() > K) q.pop();
        return q.top();
    }
};
