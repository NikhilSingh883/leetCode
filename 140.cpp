#define ll long long int
vector<string> ans;
class Solution {
public:
    bool check(ll idx,ll n,string s,unordered_map<string,ll> &mp,vector<ll> &dp,string t){
        if(idx == n){
            t.pop_back();
            ans.push_back(t);
            return true;
        } 
        if(dp[idx]==0) return dp[idx];
        
        string temp;
        dp[idx] =0;
        
        for(ll j= idx;j<n;j++){
            temp += s[j];
            if(mp[temp] && check(j+1,n,s,mp,dp,t+temp+" "))
                dp[idx] = 1;
        }
        
        return dp[idx];
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        ll n = s.size();
        ans.clear();
        vector<ll> dp(n+1,-1);
        unordered_map<string,ll> mp;
        
        for(auto x:wordDict) mp[x]++;
        bool a =  check(0,n,s,mp,dp,"");
        
        return ans;
    }
};