class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        vector<string> phone = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        vector<string> ans;
        function<void(int, string)> solve = [&](int index, string current) {
            if (index == digits.size()) {
                ans.push_back(current);
                return;
            }
            string letters = phone[digits[index] - '0'];
            for (char ch : letters) {
                solve(index + 1, current + ch);
            }
        };
        solve(0, "");
        return ans;
    }
};
