class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> x;
        vector<int> ans;
        for(int i = 0; i< nums.size(); i++){
            int complement = target - nums[i];
            if(x.count(complement)){
                ans.push_back(x[complement]);
                ans.push_back(i);
            }
            x[nums[i]] = i;
        }
        return ans;
    }
};