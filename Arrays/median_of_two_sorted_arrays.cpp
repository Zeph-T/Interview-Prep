class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        if(n1 > n2)return findMedianSortedArrays(nums2,nums1);
        double median  = 0;
        int total = n1 + n2;
        int left = 0;
        int right = n1;
        
        while(left <= right){
            int mid1 = (left +right)/2;
            int mid2 = (total + 1)/2 - mid1;
    
            
            int alm1 = mid1 <=0 ? INT_MIN : nums1[mid1-1];
            int al  = (mid1 == n1) ? INT_MAX : nums1[mid1];
            int blm1 = mid2 <= 0 ? INT_MIN : nums2[mid2-1];
            int bl = (mid2 == n2) ? INT_MAX : nums2[mid2];
            
            
            if(alm1 <= bl and blm1 <= al ){
                if(total % 2 == 0){
                    return (double)(min(al,bl) + max(alm1,blm1))/2;
                    
                }else{
                    return (double)max(alm1,blm1);
                }
            }else if(alm1 > bl){
                right = mid1 - 1;
            }else if(blm1 > al){
                left = mid1 + 1;
            }
        }
        return -1;
    }
};