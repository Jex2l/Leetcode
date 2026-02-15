class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int m = nums1.size(), n = nums2.size();
        int left = 0, right = m;
        while (left <= right) {
            int partitionA = (left + right) / 2;
            int partitionB = (m + n + 1) / 2 - partitionA;
            int maxLeftA = (partitionA == 0) ? INT_MIN : nums1[partitionA - 1];
            int minRightA = (partitionA == m) ? INT_MAX : nums1[partitionA];
            int maxLeftB = (partitionB == 0) ? INT_MIN : nums2[partitionB - 1];
            int minRightB = (partitionB == n) ? INT_MAX : nums2[partitionB];
            if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
                if ((m + n) % 2 == 0) {
                    return (max(maxLeftA, maxLeftB) +
                            min(minRightA, minRightB)) /
                           2.0;
                } else {
                    return max(maxLeftA, maxLeftB);
                }
            } else if (maxLeftA > minRightB) {
                right = partitionA - 1;
            } else {
                left = partitionA + 1;
            }
        }
        return 0.0;
    }
};

// O(m+n)
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> total;
//         int a = 0, b = 0;
//         while(a < nums1.size() && b < nums2.size()){
//             if(nums1[a] <= nums2[b]){
//                 total.push_back(nums1[a++]);
//             } else {
//                 total.push_back(nums2[b++]);
//             }
//         }
//         while(a < nums1.size())
//             total.push_back(nums1[a++]);

//         while(b < nums2.size())
//             total.push_back(nums2[b++]);
//         int n = total.size();
//         if(n % 2 == 1)
//             return total[n/2];
//         else
//             return (total[n/2 - 1] + total[n/2]) / 2.0;
//     }
// };