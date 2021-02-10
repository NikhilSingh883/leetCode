#define ll long long 

class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        ll n = t.size();
        
        ll dp[n+1][n+1];
                
        dp[0][0] = t[0][0];
        
        ll row = 1;
        while(row<n){
            
            dp[row][0] = t[row][0] + dp[row-1][0];
            dp[row][row] = t[row][row] + dp[row-1][row-1];
            
            for(int i=1;i<row;i++)
                dp[row][i] = t[row][i] + min(dp[row-1][i],dp[row-1][i-1]);
            row++;
        }
        
        ll ans =INT_MAX;
        for(int j=0;j<n;j++){
            ans = min(ans,dp[n-1][j]);
            cout << dp[n-1][j] <<" ";
        }
        
        return ans;
    }
};