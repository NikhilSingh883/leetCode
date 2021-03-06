class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        
        map<int,vector<int>> G;
        
        map<int,int> mp;
        
        for(int i=0;i<numCourses;i++) mp[i] = 0;
        
        for(auto v:pre){
            G[v[1]].push_back(v[0]);
            mp[v[0]]++;
        }
        
        queue<int> q;
        
        for(auto x:mp)
            if(x.second == 0) q.push(x.first);
        
        int item = 0;
        
        while(!q.empty()){
            int top = q.front();
            q.pop();
            item++;
            
            for(auto x:G[top]){
                mp[x]--;
                if(mp[x] ==0)
                    q.push(x);
            }
            
        }

        return item == numCourses;
    }
};