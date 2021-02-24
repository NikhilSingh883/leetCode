#define ll long long int
class Solution {
public:
    bool check(ll idx,ll n,string s,unordered_map<string,ll> &mp,vector<ll> &dp){
        if(idx == n) return true;
        if(dp[idx]!=-1) return dp[idx];
        
        string temp;
        for(ll j= idx;j<n;j++){
            temp += s[j];
            if(mp[temp] && check(j+1,n,s,mp,dp))
                return dp[idx] = 1;
        }
        return dp[idx] = 0;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        ll n = s.size();
        
        vector<ll> dp(n+1,-1);
        unordered_map<string,ll> mp;
        
        for(auto x:wordDict) mp[x]++;
        return check(0,n,s,mp,dp);
    }
};