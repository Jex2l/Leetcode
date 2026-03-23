class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> x;
        for(int i = 0; i< nums.size(); i++){
            int complement = target - nums[i];
            if(x.count(complement)) return {x[complement], i};
            x[nums[i]] = i;
        }
        return {};
    }
};