class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for(string t : strs){
            int n = t.size();
            s+=to_string(n);
            s+="/";
            s+=t;
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string>res;
        int n = s.size();
        int idx = 0;

        while(idx < n){
            int len = 0;
            while(isdigit(s[idx])){
                len = len*10 + (s[idx]-'0');
                idx++;
            }
            idx++;
            int st = idx;
            string temp = "";
            while(idx < st + len){
                temp.push_back(s[idx]);
                idx++;
            }
    
            res.push_back(temp);
        }
        return res;

    }
};
