class Solution {
public:
    bool isMatch(string A, string B) {
        
        int n = A.size();
        int m = B.size();
        
        int dp[50][50];
        memset(dp,false,sizeof dp);
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 && j==0) dp[i][j] = true;
                else if(i==0)
                    dp[i][j] = B[j-1] =='*' && dp[i][j-2];
                else if(j==0)
                    dp[i][j] = false;
                else {
                    if(B[j-1]=='*')
                        dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (B[j - 2] == A[i - 1] || B[j - 2] == '.'));
                    else 
                        dp[i][j] = dp[i-1][j-1] ? A[i-1]==B[j-1] || B[j-1]=='.':0;
                }
            }
        }
        
        return dp[n][m];
    }
};0