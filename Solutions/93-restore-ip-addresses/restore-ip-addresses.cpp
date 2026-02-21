class Solution {
public:
    void backtrack(string& s, int length, vector<string>& result, vector<string>& currentSegments, int startindex) {
        if (currentSegments.size() == 4) {
            if (startindex == length)  result.push_back(currentSegments[0] + "." + currentSegments[1] + "." + currentSegments[2] + "." + currentSegments[3]);
            return;}
        int currentnum = 0;
        for(int i = startindex; i < min(length, startindex + 3); i++) {
            currentnum = currentnum * 10 + (s[i] - '0');
            if(currentnum > 255) break;
            if(i > startindex && s[startindex] == '0') break;
            currentSegments.push_back(s.substr(startindex, i - startindex + 1));
            backtrack(s, length, result, currentSegments, i + 1);
            currentSegments.pop_back();}}
    vector<string> restoreIpAddresses(string s) {
        int length = s.size();
        vector<string> result;
        vector<string> currentSegments;
        backtrack(s, length, result, currentSegments, 0);
        return result;}};