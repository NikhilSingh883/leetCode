class Solution {
public:
    
    int house(vector<int>&nums,int start,int n){
        if(n-start<=1) return nums[start];
        
        vector<int> f(n);
        
        f[start] = nums[start];
        f[start+1] = max(nums[start],nums[start+1]);
        
        for(int i=start+2;i<n;i++)
            f[i] = max(f[i-1],f[i-2]+nums[i]);
        
        return f[n-1];
    }
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n==0) return 0;
        if(n==1) return nums[0];
        
        return max(house(nums,0,n-1),house(nums,1,n));
    }
};