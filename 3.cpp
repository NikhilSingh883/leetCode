class Solution {
public:
    int res, l, m[128];
    int lengthOfLongestSubstring(string s) {
        for(int r = 0; r < s.size(); r++) {
           if(m[s[r]]) {
               while(s[l] != s[r]) m[s[l++]] = 0;
               l++;
           }
           res = max(res, r-l+1);
           m[s[r]] = 1;
        }
        return res;
    }
};