class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& pre) {
        map<int,vector<int>> G;
        
        map<int,int> mp;
        
        if(n==1) return {0};
        
        for(auto v:pre){
            G[v[1]].push_back(v[0]);
            G[v[0]].push_back(v[1]);
            mp[v[0]]++;
            mp[v[1]]++;
        }
        
        vector<int> cou;
        set<int> s;
        for(auto x:mp)
            if(x.second == 1) cou.push_back(x.first);
    
        int rem = n;
        
        while(rem > 2){
            rem -= cou.size();
            vector<int> newL;
            for(auto leave: cou){
                if(s.count(leave)) continue;
                s.insert(leave);
                
                for(auto x:G[leave])
                    if(--mp[x] == 1)
                        newL.push_back(x);
            }
            cou = newL;
            
        }
        
        return cou;
    }
};