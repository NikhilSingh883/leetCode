class Solution {
public:
    
    bool isPal(string s,int st,int en){
        while(st<en){
            if(s[st] != s[en]) return false;
            st++;
            en--;
        }
        return true;
    }
    int palPar(string s,int st,int en,vector<vector<int>>& dp){
        if(st == en)
            return 0;
        
        if(dp[st][en]!=-1) return dp[st][en];
        
        if(isPal(s,st,en)) return dp[st][en] = 0;
        

        int left,right;
        int ans = INT_MAX;
        
        for(int k = st;k<en;k++){
            if(isPal(s,st,k)){
                dp[st][k] = left = 0;

                if(dp[k+1][en]!=-1) right = dp[k+1][en];
                else dp[k+1][en] = right = palPar(s,k+1,en,dp);

                ans = min(ans,1 + left + right);
            }
        }
        
        return dp[st][en] = ans;
    }
    
    int minCut(string& s) {
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        return palPar(s,0,n-1,dp);
    }
};