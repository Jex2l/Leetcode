class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string temp = "";

        // Collect words, ignoring multiple spaces
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (!temp.empty()) {
                    words.push_back(temp);
                    temp.clear();
                }
            } else {
                temp.push_back(s[i]);
            }
        }

        // Push last word if exists
        if (!temp.empty()) words.push_back(temp);

        // Reverse words 
        reverse(words.begin(), words.end());

        // Build answer with single-space separation
        string ans = "";
        for (int i = 0; i < words.size(); i++) {
            ans += words[i];
            if (i != words.size() - 1) ans += " ";
        }

        return ans;
    }
};
