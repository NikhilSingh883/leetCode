class Solution {
public:
    int dp[1001][1001];
    int ways(int i,int j,string s,string t){
        
        if(i>s.size()) return 0;
        
        if(i==s.size() && j==t.size())
            return 1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans =0;
        
        if(s[i]==t[j]) ans += ways(i+1,j+1,s,t);
        ans += ways(i+1,j,s,t);
        
        return dp[i][j] = ans;
    }
    
    int numDistinct(string s, string t) {
        
        memset(dp,-1,sizeof dp);
        return ways(0,0,s,t);
    }
};