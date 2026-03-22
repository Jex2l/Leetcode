class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> x;
        for (int i : nums) x[i]++;
        vector<vector<int>> a(nums.size() + 1);
        for (auto &i : x)  a[i.second].push_back(i.first);
        vector<int> ans;
        for (int i = a.size() - 1; i >= 0 && ans.size() < k; i--) {
            for (int val : a[i]) {
                ans.push_back(val);
                if (ans.size() == k) break;
            }
        }
        return ans;
    }
};