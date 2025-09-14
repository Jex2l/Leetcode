class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        vector<int> a;
        vector<int> b;
        for(int i = 0; i<s.size(); i++){
            char c = s[i];
            int ascii_value = c;
            a.push_back(ascii_value); 
        }
        for(int i = 0; i<t.size(); i++){
            char c = t[i];
            int ascii_value = c;
            b.push_back(ascii_value); 
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if(a == b){
            return true;
        }
        return false;        
    }
};