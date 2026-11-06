class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        ranges::sort(logs, {}, [](auto& log) { return log[1]; });  
        logs.push_back({0, INT_MAX});  
        vector<int> order(queries.size());
        iota(order.begin(), order.end(), 0);
        ranges::sort(order, {}, [&](int i) { return queries[i]; });  
        vector<int> cnt(n + 1), ans(queries.size());  
        int busy = 0, lo = 0, hi = 0; 
        for (int i : order) {
            int q = queries[i];
            for (; logs[hi][1] <= q; ++hi) 
                busy += cnt[logs[hi][0]]++ == 0;
            for (; logs[lo][1] < q - x; ++lo) 
                busy -= --cnt[logs[lo][0]] == 0;
            ans[i] = n - busy;
        }
        return ans;
    }
};
