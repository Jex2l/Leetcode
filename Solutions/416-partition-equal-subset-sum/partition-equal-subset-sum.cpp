bool solve(int index, vector<int>& nums, int n, int target, vector<vector<int>> &dp){
    if(index >= n){
        return false;
    }
    if(target <0){
        return false;
    }
    if(target == 0){
        return true;
    }
    if(dp[index][target] != -1){
        return dp[index][target];
    }
    bool incl = solve(index + 1, nums, n, target - nums[index], dp);
    bool excl = solve(index + 1, nums, n, target - 0, dp);
    dp[index][target] = (incl || excl);
    return dp[index][target];
}

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int i = 0; i< nums.size(); i++){
            total = total + nums[i];
        }
        if(total & 1){
            return false;
        }
        int target = total / 2;
        vector<vector<int>> dp(n, vector<int> (target + 1, -1));
        return solve(0, nums, n, target, dp);
    }
};