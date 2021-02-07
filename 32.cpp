class Solution {
public:
    int longestValidParentheses(string s) {
        
        int n = s.size();
        stack<int> S;
        S.push(-1);
        int mxlen =0;
        int i=0;
        
        for(i;i<n;i++){
            if(s[i]=='(')
                S.push(i);
            else{
                S.pop();
                if(S.empty())
                    S.push(i);
                
                mxlen = max(mxlen,i-S.top());
            }
        }
        return mxlen;
    }
};