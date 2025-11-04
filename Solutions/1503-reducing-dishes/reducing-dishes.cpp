class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int cum = 0, total = 0;
        for (int i = satisfaction.size()-1; i >= 0; --i) {
            if (satisfaction[i] + cum > 0) {
                cum += satisfaction[i];
                total += cum;
            } else {
                break;
            }
        }
        return total;
    }
};