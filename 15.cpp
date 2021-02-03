class Solution {
public:

    
    vector<vector<int>> threeSum(vector<int>& arr) {
        set<vector<int>> ans;
        vector<vector<int>> a;
        
        int n = arr.size();
        if(n<3) return {};
        sort(arr.begin(),arr.end());
        
   for (int i=0; i<n-1; i++)
    {
        int l = i + 1;
        int r = n - 1;
        int x = arr[i];
        while (l < r)
        {
            if (x + arr[l] + arr[r] == 0)
            {
                ans.insert({x,arr[l],arr[r]});
                l++;
                r--;
            }
            else if (x + arr[l] + arr[r] < 0)
                l++;
            else
                r--;
        }
    }
        
        for(auto s:ans)
            a.push_back(s);
        
        return a;
    }
};