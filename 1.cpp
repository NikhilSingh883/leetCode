

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap{{nums[0], 0}};
        
        for (int i = 1; i < nums.size(); ++i){
            auto it = hashmap.find(target - nums[i]);
            
            if (it != hashmap.end() ){
                return {it->second, i};
            }
            hashmap[nums[i]] = i;
        }
        
        return {};
    }
};