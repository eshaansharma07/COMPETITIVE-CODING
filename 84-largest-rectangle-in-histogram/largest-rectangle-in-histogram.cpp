class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>st;
        st.push(-1);
        int ans = 0;
        for(int i = 0 ; i<n ; i++){
            while (st.top()!=-1 && heights[st.top()]>=heights[i]){
                int height = heights[st.top()];
                st.pop();
                int pse = st.top();
                int nse = i;
                int width= nse-pse-1;
                ans=max(ans, height*width);
            }
            st.push(i);
        }
        while (st.top()!= -1){
            int height = heights[st.top()];
            st.pop();
            int pse = st.top();
            int nse = n;
            int width = nse - pse - 1;
            ans = max(ans, height * width);
        }
        return ans;
    }
};