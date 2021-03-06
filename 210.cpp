class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        map<int,vector<int>> G;
        
        map<int,int> mp;
        
        for(int i=0;i<numCourses;i++) mp[i] = 0;
        
        for(auto v:pre){
            G[v[1]].push_back(v[0]);
            mp[v[0]]++;
        }
        
        queue<int> q;
        
        vector<int> cou;
        
        for(auto x:mp)
            if(x.second == 0) q.push(x.first);
    
        
        while(!q.empty()){
            int top = q.front();
            q.pop();
            cou.push_back(top);
            
            for(auto x:G[top]){
                mp[x]--;
                if(mp[x] ==0)
                    q.push(x);
            }
            
        }

        if(cou.size() == numCourses) return cou;
        return {};
    }
};