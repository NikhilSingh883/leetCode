class Solution {
public:
    
    void solve(int l1,int l2,int n,string s,vector<string>& st){
        if(l2>l1) return;
        
        if(s.size()==2*n){
            if(l1 == l2) st.push_back(s);
            return;
        }
        
        solve(l1+1,l2,n,s+'(',st);
        solve(l1,l2+1,n,s+')',st);
        
        return;
    }
    
    vector<string> generateParenthesis(int n) {
        
        vector<string> an;
        solve(0,0,n,"",an);
        
        return an;
        
    }
};