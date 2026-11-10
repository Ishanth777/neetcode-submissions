class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int max_len = 0;
        unordered_map<char,int>mp;
        int max_freq = 0;
        int l =0;

        for(int r=0;r<n;r++){
            mp[s[r]]++;
            max_freq = max(max_freq,mp[s[r]]);
            while(l<n && r-l+1-max_freq>k){
                mp[s[l]]--;
                if(mp[s[l]]==0)mp.erase(s[l]);
                l++;
            }
            max_len = max(max_len,r-l+1);
        }
        return max_len;
    }
};
