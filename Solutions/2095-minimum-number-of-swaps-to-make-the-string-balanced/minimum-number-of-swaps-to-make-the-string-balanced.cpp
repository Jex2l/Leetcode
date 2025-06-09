class Solution {
public:
    int minSwaps(string s) {
        stack<char>x;
        for(int i = 0; i<s.size(); i++){
            char ch = s[i];
            if(ch == '['){
                x.push(ch);
            }
            else{
                if(!x.empty()&& x.top() == '['){
                    x.pop();
                }
                else{
                        x.push(ch);
                }
            }
        }
        int a = 0, b = 0;
        while(!x.empty()){
                if(x.top()== '['){
                    b++;
                }
                else{
                    a++;
                }
                x.pop();
            }
        int ans = (a+1)/2 + (b+1)/2;
        return ans/2;
    }
};