class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        if(m > n)return findMedianSortedArrays(nums2,nums1);
        int len = (m+n+1)/2;
        int low = 0;
        int high = m;

        while(low <= high){
            int mid1 = low + (high-low)/2;
            int mid2 = len - mid1;
            int l1 = -1e9,l2=-1e9;
            int r1 = 1e9,r2=1e9;
            if(mid1 > 0)l1 = nums1[mid1-1];
            if(mid1 < m)r1 = nums1[mid1];
            if(mid2 >0)l2 = nums2[mid2-1];
            if(mid2 < n)r2 = nums2[mid2];

            if(l1 <= r2 && l2 <= r1){
                if((m+n)%2==0)return (double)(max(l1,l2) + min(r1,r2))/2;
                else return max(l1,l2);
            }else if(l1 > r2){
                high = mid1-1;
            }else{
                low = mid1+1;
            }
        }
        return -1;
    }
};
