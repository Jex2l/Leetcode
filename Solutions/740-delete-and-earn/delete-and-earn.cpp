class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int> count(n);
        for(auto &x : nums) count[x] += x;
        for(int i = 2; i < n; ++i) count[i] = max(count[i] + count[i - 2], count[i - 1]);
        return count[n - 1];
    }
};