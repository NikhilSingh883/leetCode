class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        int dp[n][m];
        
        memset(dp,0,sizeof dp);
        
        for(int i=0;i<n;i++) dp[i][0] = mat[i][0]=='1';
        for(int i=0;i<m;i++) dp[0][i] = mat[0][i]=='1';
        
        for(int i=1;i<n;i++)
            for(int j=1;j<m;j++)
                if(mat[i][j]=='1')
                    dp[i][j] = (mat[i][j]=='1') + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
        
        int ans =0;
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                ans = max(ans,dp[i][j]);
        
        return ans*ans;
        
    }
};