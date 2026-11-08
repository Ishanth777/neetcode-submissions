class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(int num : nums)st.insert(num);
        int max_len = 0;

        for(int num : nums){
            if(st.find(num-1)==st.end()){
                int len = 0;
                while(st.find(num+len)!=st.end()){
                    len++;
                }
                max_len = max(max_len,len);
            }
        }
        return max_len;
    }
};
