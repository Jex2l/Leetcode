class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        int res = 0;
        for(int i : nums){
            if(i > res) res = i;
        }
        int curMin = 1, curMax = 1;
        for(int x : nums){
            if(x == 0){
                curMin = 1;
                curMax = 1;
                continue;
            }
            int temp = curMax*x;
            curMax = max(x*curMax, max(x*curMin, x));
            curMin = min(temp, min(x*curMin, x));
            res = max(res, curMax);
        }
        return res;
    }
};