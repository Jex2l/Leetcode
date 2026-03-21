class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> x;
        for(char e : s) x[e]++;
        for(char e : t){
            x[e]--;
            if(x[e] < 0) return false;
        }
        return true;
    }
};
