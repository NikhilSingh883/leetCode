class Solution {
public:
    int numDecodings(string s) {
    
        if(s[0]=='0') return 0;
      int n=s.size();
      int dp[n+1];
      memset(dp,0,sizeof(dp));
        
      dp[0]=1;
      dp[1]= s[0]=='0'?0:1;
      for(int i=2;i<=n;i++)
      { 
          int n1 = (s[i-1]-'0')+10*(s[i-2]-'0');
          if((n1<=26)&&(n1>=10))
            {
                dp[i]+=(dp[i-2]);
            }       
            if((s[i-1]-'0')>=1)
            {
                dp[i]+=dp[i-1];
            }
      }
      return dp[n];
    }
};