class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> x;
        x[0] = 1;
        int ans = 0;
        int sum = 0;
        for(int i : nums){
            sum += i;
            if(x.find(sum - k) != x.end()) ans += x[sum - k];
            x[sum]++;
        }
        return ans;
    }
};