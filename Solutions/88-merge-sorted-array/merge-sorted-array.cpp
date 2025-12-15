class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // BrutForce
        // for (int j = 0, i = m; j<n; j++){
        //     nums1[i] = nums2[j];
        //     i++;
        // }
        // sort(nums1.begin(),nums1.end());

        vector<int> result;
        int l1 = 0;
        int l2 = 0;
        for(int i = 0; i< m + n; i++){
            if(l2 < nums2.size()){
                if((nums1[l1] < nums2[l2]) && (l1 < m)){
                    result.push_back(nums1[l1]);
                    l1++;
                }
                else{
                    result.push_back(nums2[l2]);
                    l2++;
                }
            }
            else{
                result.push_back(nums1[l1]);
                l1++;
            }
        }
        nums1 = result;
    }
};