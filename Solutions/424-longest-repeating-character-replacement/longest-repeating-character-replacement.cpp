class Solution {
public:
    int characterReplacement(string s, int k) {
        int start = 0;
        vector<int> frequencyMap(26, 0);
        int maxFrequency = 0;
        int longestSubstringLength = 0;
        for (int end = 0; end < s.length(); end++) {
            int currentChar = s[end] - 'A';
            frequencyMap[currentChar]++;
            maxFrequency = max(maxFrequency, frequencyMap[currentChar]);
            bool isValid = (end - start + 1 - maxFrequency <= k);
            if (!isValid) {
                int outgoingChar = s[start] - 'A';
                frequencyMap[outgoingChar]--;
                start++;
            }
            longestSubstringLength = end - start + 1;
        }
        return longestSubstringLength;
    }
};