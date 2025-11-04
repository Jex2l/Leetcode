// int solve(vector<int>& obstacles, long currlane, long currpos, vector<vector<long>> &dp) {
//     int n = obstacles.size();
//     if(currpos == n){
//         return 0;
//     }
//     if(dp[currlane][currpos] != -1){
//         return dp[currlane][currpos];
//     }
    // if(obstacles[currpos+1] != currlane){
    //     return solve(obstacles, currlane, currpos+1, dp);
    // }
    // else{
    //     int ans = INT_MAX;
    //     for(int i = 1; i<=3; i++){
    //         if(currlane != i && obstacles[currpos] != i){
    //             ans = min(ans, 1 + solve(obstacles, i, currpos,dp));
    //         }
    //     }
    //     dp[currlane][currpos] = ans;
    //     return dp[currlane][currpos];
    // }
// }
int solve(vector<int>& obstacles) {
    obstacles.push_back(0);
    int n = obstacles.size();
    vector<vector<long>> dp(4, vector<long> (obstacles.size() + 1, INT_MAX));
    dp[0][n] = 0;
    dp[1][n] = 0;
    dp[2][n] = 0;
    dp[3][n] = 0;
    for(int currpos = n-1; currpos>=0; currpos--){
        for(int currlane = 1; currlane<=3; currlane++){
            if(obstacles[currpos+1] != currlane){
                dp[currlane][currpos] = dp[currlane][currpos+1];
            }
            else{
                long ans = 1e9;
                for(int i = 1; i<=3; i++){
                    if(currlane != i && obstacles[currpos] != i){
                        ans = min(ans, 1 + dp[i][currpos + 1]);
                    }
                }
                dp[currlane][currpos] = ans;
            }
        }
    }
    return min(dp[2][0], min(1 + dp[1][0], 1+dp[3][0]));
}
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        return solve(obstacles);
    }
};


// vector<vector<int>> memo;
// int solve(int i, int lane, const vector<int>& obs, int n) {
//     if (i == n) return 0;
//     int& res = memo[i][lane];
//     if (res != -1) return res;
//     if (obs[i + 1] != lane) {
//         return res = solve(i + 1, lane, obs, n);                               
//     }
//     int best = INT_MAX / 2;
//     for (int nl = 1; nl <= 3; ++nl) {
//         if (nl == lane) continue;
//         if (obs[i] == nl) continue;
//         best = min(best, 1 + solve(i, nl, obs, n));
//     }
//     return res = best;
// }
// class Solution {
// public:
//     int minSideJumps(vector<int>& obstacles) {
//         int n = obstacles.size() - 1;
//         memo.assign(n + 1, vector<int>(4, -1));
//         return solve(0, 2, obstacles, n); 
//     }
// };