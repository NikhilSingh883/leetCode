class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        
        int dp[101][101];
        
        int m = og.size();
        int n = og[0].size();
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                dp[i][j]=0;
        
        for(int i=0;i<m;i++) {
            if(og[i][0]) break;
            dp[i][0] =1;
        }
        
        for(int i=0;i<n;i++) {
            if(og[0][i]) break;
            dp[0][i] =1;
        }
        
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++){
                if(og[i][j]) continue;
                
                if(i==0 || j==0) dp[i][j] = 1;
                else{
                    dp[i][j] += dp[i-1][j];
                    dp[i][j] += dp[i][j-1];
                }
            }
        
        return dp[m-1][n-1];
        
    }
};