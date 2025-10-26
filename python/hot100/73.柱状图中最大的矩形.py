class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(-1);
        stack<int> st;
        st.push(-1);
        int ans = 0;
        for(int right = 0; right < heights.size(); ++right){
            int h = heights[right];
            while(st.size() > 1 && heights[st.top()] >= h){
                int i = st.top();
                st.pop();
                int left = st.top();
                ans = max(ans, heights[i] * (right - left - 1));
            }
            st.push(right);
        }
        return ans;
    }
};