class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(n,1);
        int prev = nums[0];

        for(int i=1;i<n;i++){
            res[i]=(prev*res[i-1]);
            prev = nums[i];
        }
        int next = nums[n-1];
        for(int i=n-2;i>=0;i--){
            res[i]*=next;
            next*=nums[i];
        }
        return res;

    }
};
