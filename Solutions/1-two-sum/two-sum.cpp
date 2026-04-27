class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> x;
        for(int i = 0; i<n; i++){
            int complement = target - nums[i];
            if(x.count(complement)) return {x[complement], i};
            x[nums[i]] = i;
        }
        return {};
    }
};