class Solution {
public:
    
    void util(int num,int k,int n,vector<int>& ans,int sum,vector<vector<int>>& res){
        
        if(sum == n && ans.size() == k){
            res.push_back(ans);
            return;
        }
        
        if(num>9 || ans.size() > k || sum > n)
            return;
                
        for(int i=num;i<10;i++){
            ans.push_back(i);
            util(i+1,k,n,ans,sum+i,res);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ans;
        vector<vector<int>> res;
        
        util(1,k,n,ans,0,res);
        
        return res;
    }
};