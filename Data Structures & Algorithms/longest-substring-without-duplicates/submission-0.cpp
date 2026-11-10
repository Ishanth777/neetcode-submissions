class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int>mp;
        int l = 0;
        int max_len = 0;

        for(int r=0;r<n;r++){
            mp[s[r]]++;
            while(l<n && mp[s[r]]>1){
                mp[s[l]]--;
                if(mp[s[l]]==0)mp.erase(s[l]);
                l++;
            }
            max_len = max(max_len,r-l+1);
        }
        return max_len;
    }
};
