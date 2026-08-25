class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        vector<string> rows(numRows);
        int row = 0;
        bool down = true;
        for (char ch : s) {
            rows[row] += ch;
            if (row == 0)
                down = true;
            if (row == numRows - 1)
                down = false;
            if (down)
                row++;
            else
                row--;
        }
        string ans = "";
        for (string r : rows)
            ans += r;
        return ans;
    }
};
