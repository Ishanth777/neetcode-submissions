class Solution {
public:
void help(int idx,vector<int>&nums,vector<int>&temp,vector<vector<int>>&res,int tar){
    if(tar < 0 || idx >= nums.size())return;
    if(tar == 0){
        res.push_back(temp);
        return;
    }
    if(tar >= nums[idx]){
        temp.push_back(nums[idx]);
        help(idx,nums,temp,res,tar-nums[idx]);
        temp.pop_back();
    }
    help(idx+1,nums,temp,res,tar);
}
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        vector<int>temp;
        help(0,nums,temp,res,target);
        return res;
    }
};
