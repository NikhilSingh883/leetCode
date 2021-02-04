class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int n = nums.size();
        int diff = INT_MAX,sum,ans;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++){
            int x = nums[i];
            
            int l = i+1;
            int r = n-1;
            
            while(l<r){
                
                 sum=nums[i]+nums[l]+nums[r];
                
                if(abs(sum-target)<diff){
                    diff=abs(sum-target);
                    ans=sum;
                }
                
                if (sum > target)
                    r--;
                else l++;
            }
        }
        
        return ans;
        
    }
};