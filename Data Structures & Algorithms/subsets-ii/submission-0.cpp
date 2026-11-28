class Solution {
public:
void help(int idx,vector<int>&nums,vector<vector<int>>&res,vector<int>&temp){
    res.push_back(temp);
    for(int i=idx;i<nums.size();i++){
        if(i > idx && nums[i]==nums[i-1])continue;
        temp.push_back(nums[i]);
        help(i+1,nums,res,temp);
        temp.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        vector<int>temp;
        help(0,nums,res,temp);
        return res;
    }
};
