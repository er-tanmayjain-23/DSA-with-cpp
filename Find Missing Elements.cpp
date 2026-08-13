class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = nums[0];
        int maxi = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }
        unordered_set<int> st;
        for (int num : nums) {
            st.insert(num);
        }
        vector<int> ans;
        for (int i = mini; i <= maxi; i++) {
            if (st.find(i) == st.end()) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
