class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1){
            return false;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size()-1; i++){
            int x = nums[i];
            int y = nums[i+1];
            if(x == y){
                return true;
            }
        }
        return false;
    }
};