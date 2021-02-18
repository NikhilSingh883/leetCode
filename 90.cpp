class Solution {
public:
    void sub(int idx,int n,vector<int>& nums,vector<int>& a,vector<vector<int>>& ans){
        ans.push_back(a);
             
        for(int i=idx;i<n;i++)
            if(idx == i || nums[i]!=nums[i-1]){
                a.push_back(nums[i]);
                sub(i+1,n,nums,a,ans);
                a.pop_back();
            }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        vector<int> a;
        vector<vector<int>> ans;
        int n = nums.size();
        sub(0,n,nums,a,ans);
        return ans;
    }
};