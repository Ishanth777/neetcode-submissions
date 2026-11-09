class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int,int>>p(n);
        for(int i=0;i<n;i++){
            p[i] = {position[i],speed[i]};
        }
        sort(p.begin(),p.end());
        vector<double>st;
        for(int i=n-1;i>=0;i--){
            double time = (double)(target-p[i].first)/p[i].second;
            st.push_back(time);
            int m = st.size();
            if(m >= 2 && st[m-1] <= st[m-2]){
                st.pop_back();
            }
        }
        return st.size();
    }
};
