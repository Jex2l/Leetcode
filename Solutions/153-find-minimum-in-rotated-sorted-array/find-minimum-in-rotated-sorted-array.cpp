class Solution {
public:

    int pivot(vector<int> &arr, int lo, int hi) {
        while (lo < hi) {
            if (arr[lo] < arr[hi]) return lo;
            if (arr[(lo + (hi - lo) / 2)] > arr[hi]) lo = (lo + (hi - lo) / 2) + 1;
            else hi = (lo + (hi - lo) / 2);
        }
        return lo;
    }

    int findMin(vector<int>& nums) {
        return nums[pivot(nums, 0, nums.size() - 1)];
    }
};