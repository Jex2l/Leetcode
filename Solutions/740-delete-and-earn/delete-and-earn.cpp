class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> points(10001, 0);
        for(int x : nums)
            points[x] += x;
        int prev2 = 0;
        int prev1 = 0;
        for(int i = 0; i <= 10000; i++){
            int take = prev2 + points[i];
            int skip = prev1;
            int curr = max(take, skip);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
