class MedianFinder {
    priority_queue<int> lo;
    priority_queue<int, vector<int>, greater<int>> hi;
    void rebalance() {
        if (lo.size() > hi.size() + 1) {
            hi.push(lo.top()); lo.pop();
        } else if (hi.size() > lo.size() + 1) {
            lo.push(hi.top()); hi.pop();
        }
    }

public:
    MedianFinder() = default;

    void addNum(int num) {
        if (lo.empty() || num <= lo.top()) lo.push(num);
        else hi.push(num);
        rebalance();
    }

    double findMedian() const {
        if (lo.size() == hi.size()) {
            if (lo.empty()) return 0.0;
            return (lo.top() + hi.top()) / 2.0;
        }
        return (lo.size() > hi.size()) ? lo.top() : hi.top();
    }
};

vector<double> runningMedians(const vector<int>& arr) {
    MedianFinder mf;
    vector<double> out;
    out.reserve(arr.size());
    for (int x : arr) {
        mf.addNum(x);
        out.push_back(mf.findMedian());
    }
    return out;
}
