class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> x;
        unordered_map<char, int> y;
        for(int i = 0; i<s.size(); i++){
            x[s[i]]++;
            y[t[i]]++;
        }
        for(char i : s){
            if(y[i] != x[i]) return false;
        }
        return true;
    }
};