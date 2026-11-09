class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l=0;
        int r=n-1;
        int max_area = 0;
        while(l<r){
            int w = r-l;
            int h = min(heights[l],heights[r]);
            max_area = max(max_area,w*h);
            if(heights[l] < heights[r]){
                l++;
            }else{
                r--;
            }
        }
        return max_area;
    }
};
