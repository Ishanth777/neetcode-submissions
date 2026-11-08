class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;

        for(string s : strs){
            vector<int>chars(26);
            for(char c : s){
                chars[c-'a']++;
            }
            string temp = "";
            for(int i = 0; i < 26; ++i){
                if(chars[i] > 0){
                    temp += to_string(chars[i]);
                    temp += (char)('a' + i);
                }
            }
            mp[temp].push_back(s);
        }
        vector<vector<string>>ans;
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
