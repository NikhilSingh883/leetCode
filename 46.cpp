class Solution {
public:
    
    void swap(int i,int j,vector<int>& nums){
        int temp = nums[i];
        nums[i] =  nums[j];
        nums[j] =  temp;
    }
    
    void solve(int idx,vector<int>& nums,vector<vector<int>>& ans){
        if(idx == nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int i=idx;i<nums.size();i++){
            swap(idx,i,nums);
            solve(idx+1,nums,ans);
            swap(idx,i,nums);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        solve(0,nums,ans);
        return ans;
    }
};