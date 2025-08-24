class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if (multiplier == 1 || k == 0) return nums;
        using P = pair<long long,int>;
        priority_queue<P, vector<P>, greater<P>> minh;
        for (int i = 0; i < (int)nums.size(); ++i) minh.push({nums[i], i});
        while (k-- > 0) {
            auto [val, idx] = minh.top(); minh.pop();
            val = val * (long long)multiplier;
            nums[idx] = (int)val;
            minh.push({val, idx});
        }
        return nums;
    }
};
