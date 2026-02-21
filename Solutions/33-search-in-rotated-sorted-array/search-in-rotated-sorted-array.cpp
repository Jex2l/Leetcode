int findchangepoint(vector<int>& nums){
    int s = 0;
    int e = nums.size() - 1;
    while (s < e) {
        int mid = s + (e - s) / 2;
        if (nums[mid] > nums[e]) {
            s = mid + 1;
        } else {
            e = mid;
        }
    }
    return s;
}

int searchelement(vector<int>& nums, int target, int start, int end){
    while(start <= end){
        int mid = start + (end-start)/2;
        if(nums[mid] == target) return mid;
        if(nums[mid] < target) start = mid + 1;
        else end = mid -1;
    }
    return -1;
}

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return -1;
        if(nums[0] <= nums[n-1]){
            return searchelement(nums, target, 0, n-1);
        }
        int index = findchangepoint(nums);
        int right = searchelement(nums, target, index, n-1);
        if(right != -1) return right;
        return searchelement(nums, target, 0, index-1);
    }
};