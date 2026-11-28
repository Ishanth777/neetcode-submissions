class Solution {
public:
void help(int idx,vector<int>&nums,vector<int>&temp,vector<vector<int>>&res,int tar){
    if(tar == 0){
        res.push_back(temp);
        return;
    }
    for(int i=idx;i<nums.size();i++){
        if(i > idx && nums[i]==nums[i-1])continue;
        if(nums[i] > tar)break;
        temp.push_back(nums[i]);
        help(i+1,nums,temp,res,tar-nums[i]);
        temp.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<int>temp;
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        help(0,nums,temp,res,target);
        return res;

    }
};
