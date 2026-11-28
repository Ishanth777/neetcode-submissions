class Solution {
public:
void help(int idx,vector<int>&nums,vector<vector<int>>&res,vector<int>&temp){
    if(idx == nums.size()){
        res.push_back(temp);
        return;
    }
    temp.push_back(nums[idx]);
    help(idx+1,nums,res,temp);
    temp.pop_back();
    help(idx+1,nums,res,temp);

}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>temp;
        help(0,nums,res,temp);
        return res;
    }
};
