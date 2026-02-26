class Solution {
public:

    int pivot(vector<int> &arr, int lo, int hi) {
        while (lo < hi) {
            if (arr[lo] < arr[hi]) return lo;
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] > arr[hi]) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }

    int findMin(vector<int>& nums) {
        return nums[pivot(nums, 0, nums.size() - 1)];
    }
};