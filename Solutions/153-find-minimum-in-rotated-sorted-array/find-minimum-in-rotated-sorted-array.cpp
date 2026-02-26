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
        int n = nums.size() - 1;
        // if(nums[0] <= nums[n]) return nums[0];
        int ans = nums[pivot(nums, 0, n)];
        return ans;
    }
};