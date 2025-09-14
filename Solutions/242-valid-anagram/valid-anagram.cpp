class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        vector<int> arr(26, 0);
        for (char ch : s) {
            arr[ch - 'a']++;
        }
        for (char ch : t) {
            if (arr[ch - 'a'] == 0) {
                return false;
            }
            arr[ch - 'a']--;
        }

        return true;      
    }
};