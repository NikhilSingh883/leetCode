class Solution {
public:
    
    void sortColors(vector<int>& nums) {
        int it =0,i=0;
        int j = nums.size() -1;
        int v = 1;
        while(i<=j){
            if(nums[i]>1){
                swap(nums[i],nums[j]);
                j--;
            }
            else if(nums[i] < 1){
                swap(nums[i],nums[it]);
                it++;
                i++;
            }
            else i++;
        }
    }
};