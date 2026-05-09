class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq1(26, 0);
        for(char c : magazine) freq1[c - 'a']++;
        vector<int> freq2(26, 0);
        for(char c : ransomNote) freq2[c - 'a']++;
        for(int i =0; i<freq2.size();i++){
            if(freq1[i] < freq2[i]) return false;
        }
        return true;
    }
};