class Solution {
public:
    string expand(string &s, int l, int r) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        return s.substr(l + 1, r - l - 1);
    }
    string longestPalindrome(string s) {
        string best = "";
        for (int i = 0; i < s.size(); i++) {
            string odd = expand(s, i, i);
            string even = expand(s, i, i + 1);
            if (odd.size() > best.size()) best = odd;
            if (even.size() > best.size()) best = even;
        }

        return best;
    }
};