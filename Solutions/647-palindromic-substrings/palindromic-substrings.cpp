class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int start = 0;
        int end = 0;
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= 1; j++){
                int left = i;
                int right = i + j;

                while(left >= 0 && right < n && s[left] == s[right]){
                    left--;
                    right++;
                    count++;
                }
                left++;
                right--;
            }
        }
        return count;
    }
};