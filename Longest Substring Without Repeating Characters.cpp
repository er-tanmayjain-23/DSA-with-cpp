class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            bool seen[256] = {false};
            for (int j = i; j < s.length(); j++) {
                if (seen[s[j]])
                    break;
                seen[s[j]] = true;
                ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};
