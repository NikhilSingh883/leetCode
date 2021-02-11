class Solution {
public:
    void solve(vector<int>& pat,int idx,int sum,int tar,vector<vector<int>>& ans,vector<int>& can){
        if(sum > tar) return;
        
        if(sum==tar){
            if(find(ans.begin(),ans.end(),pat) == ans.end())
                ans.push_back(pat);
            return;
        }
        
        for(int i=idx;i<can.size();i++){
            pat.push_back(can[i]);
            solve(pat,i+1,sum+can[i],tar,ans,can);
            pat.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        sort(candidates.begin(),candidates.end());
        solve(temp,0,0,target,ans,candidates);
        return ans;
    }
};