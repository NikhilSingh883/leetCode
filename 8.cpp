class Solution {
public:
    int myAtoi(string s) {
        int neg = 1;
        long long num=0;
        
        int idx =0;
        while (idx < s.length() && s[idx] == ' ')
            idx++;
        
        if(s[idx]=='-') neg = -1,idx++;
        else if(s[idx]=='+') idx++;

        
        for(idx;idx<s.length();idx++){
            
            if(!isdigit(s[idx])) break;

            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && s[idx] - '0' > INT_MAX % 10)) {
                return (neg == 1) ? INT_MAX : INT_MIN;
            }
            
            num*=10;
            num += (s[idx]-'0');
            

        }

        
        return neg * num;
    }
};