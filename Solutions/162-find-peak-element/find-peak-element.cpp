class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // long long start = 0;
        // long long end = nums.size() - 1;
        // long long mid = start + (end - start) / 2;
        // while (start < end) {
        //     if (nums[mid] < nums[mid+1]) {
        //         start = mid + 1;
        //     }
        //     else {
        //         end = mid;
        //     }
        //     mid = start + (end - start) / 2;
        // }
        // return start;
        vector<int> x = nums;
        sort(x.begin(), x.end());
        int a = x[x.size() - 1];
        for(int i = 0; i< nums.size(); i++){
            if(nums[i] == a){
                return i;
            }
        }
        return 0;
    }
};