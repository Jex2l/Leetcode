class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        for (int i = 0; i < s.length(); i++) {
            if (isalnum(s[i])) {
                temp.push_back(tolower(s[i]));
            }
        }
        int st = 0;
        int e = temp.length() - 1;
        while (st < e) {
            if (temp[st] != temp[e]) {
                return false;
            }
            st++;
            e--;
        }
        return true;
    }
};
