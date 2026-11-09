class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>st;
        vector<int>pse(n,-1);
        vector<int>nse(n,n);

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[i] <= heights[st.top()]){
                nse[st.top()] = i;
                st.pop();
            }
            if(!st.empty()){
                pse[i] = st.top();
            }
            st.push(i);
        }
        int max_area = 0;

        for(int i=0;i<n;i++){
            int h = heights[i];
            int w = nse[i] - pse[i] - 1;
            max_area = max(max_area,h*w);
        }
        return max_area;
    }
};
