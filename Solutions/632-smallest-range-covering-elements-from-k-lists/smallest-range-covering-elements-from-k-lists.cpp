class node {
public:
    int data;
    int row;
    int col;
    node(int d, int r, int c) : data(d), row(r), col(c) {}
};

class compare {
public:
    bool operator()(const node& a, const node& b) const {
        return a.data > b.data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<node, vector<node>, compare> minHeap;
        int maxi = INT_MIN;
        for (int r = 0; r < (int)nums.size(); ++r) {
            if (!nums[r].empty()) {
                minHeap.emplace(nums[r][0], r, 0);
                maxi = max(maxi, nums[r][0]);
            }
        }
        if ((int)minHeap.size() != (int)nums.size()) return {};
        int start = minHeap.top().data;
        int end = maxi;
        while (!minHeap.empty()) {
            node cur = minHeap.top();
            minHeap.pop();
            int mini = cur.data;
            if (maxi - mini < end - start) {
                start = mini;
                end = maxi;
            }
            if (cur.col + 1 < (int)nums[cur.row].size()) {
                int nextVal = nums[cur.row][cur.col + 1];
                maxi = max(maxi, nextVal);
                minHeap.emplace(nextVal, cur.row, cur.col + 1);
            } else {
                break;
            }
        }
        return {start, end};
    }
};
