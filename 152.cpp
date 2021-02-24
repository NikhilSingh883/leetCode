#define ll long long int
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        ll n = nums.size();
        
        int neg;
        int pos;
        
        pos = 1;
        neg = 1;
        int ans = INT_MIN;
        for(ll i=0;i<n;i++){
            if(nums[i]<0)
                swap(pos,neg);
                pos = max(pos*nums[i],nums[i]);
                neg = min(neg*nums[i],nums[i]);
            ans = max(ans,pos);
        }
        
        return ans;
    }
};