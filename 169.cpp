class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        if(n==1) return nums[0];
        sort(nums.begin(),nums.end());

        int ele = nums[0];
        int maxO = 1;
        
        for(int i=1;i<n;i++){
            if(nums[i] == ele){
                maxO++;
                if(maxO > n/2) return ele;
            }
            else{
                ele = nums[i];
                maxO=1;
            }
        }
        
        return -1;
    }
};