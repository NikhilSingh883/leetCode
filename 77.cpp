class Solution {
public:
    
    void com(int idx,vector<int>& a,int n,int k,vector<vector<int>>& ans){
        if(a.size()==k){
            ans.push_back(a);
            return;
        }
        
        for(int i=idx;i<=n;i++){
            a.push_back(i);
            com(i+1,a,n,k,ans);
            a.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        com(1,temp,n,k,ans);
        
        return ans;
    }
};