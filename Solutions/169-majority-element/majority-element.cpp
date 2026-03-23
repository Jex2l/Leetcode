class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> x;
        int n = nums.size();
        for(int i : nums){
            x[i]++;
            if(x[i] > n/2) return i;
        }
        return 0;
    }
};