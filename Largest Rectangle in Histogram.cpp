class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ans = 0;
        for (int i = 0; i <= heights.size(); i++) {
            int curr = (i == heights.size()) ? 0 : heights[i];
            while (!st.empty() && heights[st.top()] > curr) {
                int h = heights[st.top()];
                st.pop();
                int width;
                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;
                ans = max(ans, h * width);
            }
            st.push(i);
        }
        return ans;
    }
};
