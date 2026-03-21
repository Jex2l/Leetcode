class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> y;
        for(int i =0; i<nums.size(); i++){
            int opposite = target - nums[i];
            if(y.contains(opposite)) return {y[opposite], i};
            y[nums[i]] = i;
        }
        return {};
    }
};