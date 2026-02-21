int findPivot(vector<int> &arr, int lo, int hi) {
    while (lo <= hi) {
        if (arr[lo] <= arr[hi])         return lo;
        int mid = (lo + hi) / 2;
        if (arr[mid] > arr[hi]) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

int binarySearch(vector<int> &arr, int lo, int hi, int x) {
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = findPivot(nums, 0, n - 1);
        if (nums[pivot] == target) return pivot;
        if (pivot == 0) return binarySearch(nums, 0, n - 1, target);
        if (nums[0] <= target) return binarySearch(nums, 0, pivot - 1, target);
        return binarySearch(nums, pivot + 1, n - 1, target);
    }
};