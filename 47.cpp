class Solution {
public:
    
    void swap(int i,int j,vector<int>& nums){
        int temp = nums[i];
        nums[i] =  nums[j];
        nums[j] =  temp;
    }
    
    void solve(int idx,vector<int>& nums,map<vector<int>,int>& mp){
        if(idx == nums.size()){
            mp[nums] ++;
            return;
        }
        
        for(int i=idx;i<nums.size();i++){
            if(nums[idx]!=nums[i] || idx==i){
                swap(idx,i,nums);
                solve(idx+1,nums,mp);
                swap(idx,i,nums);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        map<vector<int>,int> mp;
        solve(0,nums,mp);
        
        for(auto x:mp)
            ans.push_back(x.first);
        
        return ans;
    }
};