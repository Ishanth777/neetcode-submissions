class Solution {
public:
long long help(int val,vector<int>&piles){
    long long time = 0;
    for(int i=0;i<piles.size();i++){
        time+=(piles[i] + val -1)/val;
    }
    return time;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int res = 0;

        while(low <= high){
            int mid = low + (high-low)/2;
            long long val = help(mid,piles);
            if(val <= h){
                res = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return res;
    }
};
