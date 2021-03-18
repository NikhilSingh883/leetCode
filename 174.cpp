class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& d) {
        
        int n = d.size();
        int m = d[0].size();
        
        int dp[n][m];
        
        dp[n-1][m-1] = d[n-1][m-1] <= 0 ? abs(d[n-1][m-1]) + 1: 1;
        
        for(int i = n-2;i>=0;i--){
            int x = dp[i+1][m-1] - d[i][m-1];
            dp[i][m-1] = x <=0 ? 1:x;
        }
        for(int i = m-2;i>=0;i--){
            int x = dp[n-1][i+1] - d[n-1][i];
            dp[n-1][i] = x <=0 ? 1:x;
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
               int x = min(dp[i+1][j] - d[i][j], dp[i][j+1] - d[i][j]);
                dp[i][j] = x <= 0 ? 1 : x;
            }
        }
        
        return dp[0][0];
        
    }
};