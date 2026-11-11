class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        int min_len = 1e9;
        int count = 0;
        int st = -1;
        if(n > m)return "";
        unordered_map<char,int>mp;
        for(char c : t)mp[c]++;

        int l = 0;
        for(int r=0;r<m;r++){
            if(mp[s[r]]>0)count++;
            mp[s[r]]--;
            while(count==n){
                mp[s[l]]++;
                if(mp[s[l]] > 0)count--;
                if(r-l+1 < min_len){
                    min_len = r-l+1;
                    st = l;
                }
                l++;
            }
            
        }
        if(st==-1)return "";
        return s.substr(st,min_len);
    }
};
