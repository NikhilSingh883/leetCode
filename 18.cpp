class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int i = 0;
        int j = 0;
        int left = 0;
        int right = 0;
        vector< vector<int> > quadruplets;

        sort(nums.begin(), nums.end());

        for (i = 0; i < nums.size(); ++i) {
            // to avoid duplicacy
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (j = i + 1; j < nums.size(); ++j) {
            // to avoid duplicacy
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                int new_target = target - nums[i] - nums[j];

                left = j + 1;
                right = nums.size() - 1;

                while (left < right) {
                    int sum = nums[left] + nums[right];
                    if (sum > new_target) {
                        right--;
                    }
                    else if (sum < new_target) {
                        left++;
                    }
                    else {
                        quadruplets.push_back({nums[i],nums[j],nums[left],nums[right]});
                        // to avoid duplicacy
                        while (nums[++left] == nums[left - 1] && left < right);
                    }
                }
            }
        }

        return quadruplets;
    }
};