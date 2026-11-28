class Solution {
public:
void help(int idx,string &digits,string temp,vector<string>&res,unordered_map<int,vector<char>>&mp){
    if(idx == digits.size()){
        res.push_back(temp);
        return;
    }
    
    for(char c : mp[digits[idx]-'0']){
        temp.push_back(c);
        help(idx+1,digits,temp,res,mp);
        temp.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        unordered_map<int,vector<char>>mp={
            {2 , {'a','b','c'}},
            {3 , {'d','e','f'}},
            {4 , {'g','h','i'}},
            {5 , {'j','k','l'}},
            {6 , {'m','n','o'}},
            {7 , {'p','q','r','s'}},
            {8 , {'t','u','v'}},
            {9 , {'w','x','y','z'}}
        };
        vector<string>res;
        if(digits.size()==0)return res;
        string temp;
        help(0,digits,temp,res,mp);
        return res;
    }
};
