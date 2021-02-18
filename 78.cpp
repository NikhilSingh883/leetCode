class Solution {
public:
    
    void sub(vector<int>& a,vector<int>& nums,int idx,int n,vector<vector<int>>&ans){

        ans.push_back(a);
        
        if(idx >= n) return;

        for(int i=idx;i<n;i++){
            a.push_back(nums[i]);
            sub(a,nums,i+1,n,ans);
            a.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> b;
        int n = nums.size();
        
        sub(b,nums,0,n,ans);
        return ans;
    }
};