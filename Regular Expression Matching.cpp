class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty())
            return s.empty();
        bool first = !s.empty() && (s[0] == p[0] || p[0] == '.');
        if (p.length() >= 2 && p[1] == '*') {
            return isMatch(s, p.substr(2)) ||
                   (first && isMatch(s.substr(1), p));
        }
        return first && isMatch(s.substr(1), p.substr(1));
    }
};
