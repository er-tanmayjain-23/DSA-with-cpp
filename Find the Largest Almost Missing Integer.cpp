class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        map<int, int> mp;
        for (int i = 0; i <= nums.size() - k; i++) {
            set<int> s;
            for (int j = i; j < i + k; j++) {
                s.insert(nums[j]);
            }
            for (int x : s) {
                mp[x]++;
            }
        }
        int ans = -1;
        for (auto p : mp) {
            if (p.second == 1) {
                ans = p.first;
            }
        }
        return ans;
    }
};
