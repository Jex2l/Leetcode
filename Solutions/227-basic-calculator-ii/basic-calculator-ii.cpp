#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int i = 0;
        int curr = 0;
        int prev = 0;
        int res = 0;
        char curr_operation = '+';

        while(i < s.size()) {
            char curr_char = s[i];

            if(isdigit(curr_char)) {
                curr = curr * 10 + (curr_char - '0');
            }

            if((!isdigit(curr_char) && curr_char != ' ') || i == s.size()-1) {

                if(curr_operation == '+') {
                    res += curr;
                    prev = curr;
                }
                else if(curr_operation == '-') {
                    res -= curr;
                    prev = -curr;
                }
                else if(curr_operation == '*') {
                    res -= prev;
                    res += prev * curr;
                    prev = prev * curr;
                }
                else if(curr_operation == '/') {
                    res -= prev;
                    prev = prev / curr;
                    res += prev;
                }

                curr_operation = curr_char;
                curr = 0;
            }

            i++;
        }
        return res;
    }
};
