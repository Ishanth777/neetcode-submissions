class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int>st;
        int n = temp.size();
        vector<int>nge(n,0);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && temp[i] >= temp[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                nge[i] = st.top()-i;
            }
            st.push(i);
        }
        return nge;
    }
};
