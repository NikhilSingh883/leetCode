class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        int n = strs.size();
        if(n==0) return "";
        
        string prefix = strs[0];
        
        for(int i=1;i<n;i++){
            int j=0;
            while(strs[i][j] == prefix[j] && j<prefix.size() && j<strs[i].size()){
                j++;
            }
            prefix = prefix.substr(0,j);
            if(prefix.empty()) return "";
        }
        
        return prefix;
    }
};