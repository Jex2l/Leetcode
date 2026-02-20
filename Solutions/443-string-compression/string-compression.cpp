class Solution {
public:
    int compress(vector<char>& chars) {
        int l=0;
        char prev=chars[0];
        int count =0;
        string t="";
        for(int i=0;i<chars.size();i++)
        {
            if(chars[i]==prev)
                count++;
            else
            {
                chars[l]=prev;
                l++;
                if(count>1)
                {
                    t=to_string(count);
                    for(int j=0;j<t.size();j++)
                    {
                        chars[l]=t[j];
                        l++;
                    }
                }
                count=1;
                prev=chars[i];
            }
        }
        chars[l]=prev;
        l++;
        if(count>1)
        {
            t=to_string(count);
            for(int j=0;j<t.size();j++)
            {
                chars[l]=t[j];
                l++;
            }
        }
        return l;
    }
};