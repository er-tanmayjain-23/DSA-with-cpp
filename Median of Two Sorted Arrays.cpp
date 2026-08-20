class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        for (int x : nums1)
            v.push_back(x);
        for (int x : nums2)
            v.push_back(x);
        sort(v.begin(), v.end());
        int n = v.size();
        if (n % 2 == 1)
            return v[n / 2];
        return (v[n / 2 - 1] + v[n / 2]) / 2.0;
    }
};
