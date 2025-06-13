class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> count;
        queue<int> q;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            count[ch]++;
            q.push(i);
        }
        while (!q.empty()) {
            if (count[s[q.front()]] > 1) {
                q.pop();
            } else {
                return q.front();
            }
        }
        return -1;
    }
};
