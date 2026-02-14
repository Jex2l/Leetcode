class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> total;
        int a = 0, b = 0;
        while(a < nums1.size() && b < nums2.size()){
            if(nums1[a] <= nums2[b]){
                total.push_back(nums1[a++]);
            } else {
                total.push_back(nums2[b++]);
            }
        }
        while(a < nums1.size())
            total.push_back(nums1[a++]);

        while(b < nums2.size())
            total.push_back(nums2[b++]);
        int n = total.size();
        if(n % 2 == 1)
            return total[n/2];
        else
            return (total[n/2 - 1] + total[n/2]) / 2.0;
    }
};