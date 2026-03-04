class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> a(nums.size(), 1);
        int max = 1;
        for(int i = 0; i<nums.size(); i++){
            a[i] *= max;
            max *= nums[i];
        }
        int min = 1;
        for(int i = nums.size() - 1; i>=0; i--){
            a[i] *= min;
            min *= nums[i];
        }
        return a;
    }
};