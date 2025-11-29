class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int one = nums[i];
            int target = -one;
            int s = i + 1;
            int e = n - 1;
            while (s < e) {
                long long sum = (long long)nums[s] + nums[e];
                if (sum == target) {
                    res.push_back({one, nums[s], nums[e]});
                    s++;
                    e--;
                } else if (sum < target) {
                    s++;
                } else {
                    e--;
                }
            }
        }
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};
