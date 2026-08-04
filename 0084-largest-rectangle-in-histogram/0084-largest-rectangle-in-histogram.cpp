class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = (int)heights.size();
        stack<int> st;
        int maxArea = 0;

        for(int i = 0; i <= n; i++){

            // Current height ya 0 (sentinel)
            int currH = (i == n) ? 0 : heights[i];

            while(!st.empty() && currH < heights[st.top()]){
                int h    = heights[st.top()];
                st.pop();

                // Width = left boundary to right boundary
                int w = st.empty() ? i : i - st.top() - 1;

                maxArea = max(maxArea, h * w);
            }

            st.push(i);
        }

        return maxArea;
    }
};