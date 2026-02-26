class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int target = -nums[i];
            unordered_set<int> seen;
            for(int j = i + 1; j < n; j++) {
                int complement = target - nums[j];
                if(seen.count(complement)) {
                    ans.push_back({nums[i], complement, nums[j]});
                    while(j + 1 < n && nums[j] == nums[j+1]) j++;
                }
                seen.insert(nums[j]);
            }
        }
        return ans;
    }
};