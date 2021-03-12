class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> s(nums.begin(),nums.end());
        
        int ans=0;
        
        for(auto num : nums){
            if(s.count(num-1)==0){
                int curNum = num;
                int curS = 1;
                
                while(s.count(curNum+1)){
                    curNum++;
                    curS++;
                }
                
                ans = max(ans,curS);
            }
        }
        
        return ans;
        
    }
};