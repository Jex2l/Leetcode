vector<int> nextSmallerElement(const vector<int>& arr, int n) {
    stack<int> s;
    vector<int> ans(n);
    s.push(-1);
    for (int i = n - 1; i >= 0; i--) {
        while (s.top() != -1 && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(const vector<int>& arr, int n) {
    stack<int> s;
    vector<int> ans(n);
    s.push(-1);
    for (int i = 0; i < n; i++) {
        while (s.top() != -1 && arr[s.top()] >= arr[i]) {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> next = nextSmallerElement(heights, n);
    vector<int> prev = prevSmallerElement(heights, n);
    int area = 0;
    for (int i = 0; i < n; i++) {
        int l = heights[i];
        if (next[i] == -1) next[i] = n;
        int b = next[i] - prev[i] - 1;
        int newArea = l * b;
        area = max(area, newArea);
    }
    return area;
}

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> histogram(cols, 0);
        int maxArea = 0;
        for (int i = 0; i < rows; i++) {
            // Build histogram row-wise
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    histogram[j]++;
                } else {
                    histogram[j] = 0;
                }
            }
            maxArea = max(maxArea, largestRectangleArea(histogram));
        }

        return maxArea;
    }
};