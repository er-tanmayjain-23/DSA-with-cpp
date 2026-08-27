class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s;
        for (int x : nums) {
            s.insert(x);
        }
        int multiple = k;
        while (s.count(multiple)) {
            multiple += k;
        }
        return multiple;
    }
};
