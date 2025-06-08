class Solution {
public:
    void reverseString(vector<char>& s) {
        int start = 0;
        int end = s.size()-1;
        while(start<=end){
            swap(s[start], s[end]);
            start++;
            end--;
        }
        // stack<char> strings;
        // for(int i=0; i<s.size(); i++){
        //     strings.push(s[i]);
        // }
        // s.clear();
        // while(!strings.empty()){
        //     s.push_back(strings.top());
        //     strings.pop();
        // }
    }
};