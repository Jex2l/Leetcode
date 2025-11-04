vector<vector<int>> memo;
int solve(int i, int lane, const vector<int>& obs, int n) {
    if (i == n) return 0;
    int& res = memo[i][lane];
    if (res != -1) return res;
    if (obs[i + 1] != lane) {
        return res = solve(i + 1, lane, obs, n);                               
    }
    int best = INT_MAX / 2;
    for (int nl = 1; nl <= 3; ++nl) {
        if (nl == lane) continue;
        if (obs[i] == nl) continue;
        best = min(best, 1 + solve(i, nl, obs, n));
    }
    return res = best;
}
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size() - 1;
        memo.assign(n + 1, vector<int>(4, -1));
        return solve(0, 2, obstacles, n); 
    }
};