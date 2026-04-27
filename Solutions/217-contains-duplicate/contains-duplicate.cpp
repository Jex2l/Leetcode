class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> x;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            x[nums[i]]++;
            if(x[nums[i]] > 1) return true;
        }
        return false;
    }
};