class Solution {
public:
    bool isPalindrome(string s) {
        string x;
        for(char c : s) {
            if(isalnum(c)) x.push_back(tolower(c));
        }
        string y = x;
        reverse(y.begin(), y.end());
        return x == y;
    }
};