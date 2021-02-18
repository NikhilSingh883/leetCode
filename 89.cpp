class Solution {
public:
    
    vector<int> grayCode(int n) {
        vector<int> ans;
        
        for(int i=0;i<=pow(2,n)-1;i++){
            int j = i/2;
            ans.push_back(i^j);
        }
        
        return ans;
    }
};