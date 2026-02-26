class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> one;
        unordered_map<char, int> two;
        for(char i : s){
            one[i]++;
        }
        for(char i : t){
            two[i]++;
        }
        if(one == two) return true;
        return false;
    }
};