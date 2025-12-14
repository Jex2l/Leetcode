class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // With Sorting
        // sort(nums.begin(), nums.end());
        // int x = nums.size();
        // int y;
        // while(k > 0){
        //     if(k == 1){
        //         y = nums[x-1];
        //     }
        //     k--;
        //     x--;
        // }
        // return y;

        make_heap(nums.begin(), nums.end());
        while(k > 1){
            pop_heap(nums.begin(), nums.end());
            nums.pop_back();
            k--;
        }
        // for (int i = 1; i < k; i++) {
        //     pop_heap(nums.begin(), nums.end());
        //     nums.pop_back();
        // }
        return nums.front(); 
    }
};