class Solution {
public:
    
    bool valid(string str,int st,int en){
        
        int lead =0;
        int num =0;
        
        while(st<=en){
            num *=10;
            int d = str[st] - '0';
            num += d;
            if(num==0) lead++;
            st++;
        }
        // cout << num <<" " << lead <<" ";
        if(num > 255) return false;
        
        if(num) return lead == 0;
        return lead == 1;
    }
    
    void res(string str,int idx,int n,vector<string>&ans,string s,int cnt){
        if(idx > n || cnt > 4)
            return;
        
        if(idx == n){
            if(cnt == 4){
                str.pop_back();
                ans.push_back(str);
            }
            return;
        }
        string temp;
        bool poss = true;
        for(int i= idx;i<n;i++){
            temp += s[i];
            
            if(temp.length()>3) break;
            
            poss = valid(s,idx,i);
            if(poss) res(str+temp+'.',i+1,n,ans,s,cnt+1);
            else break;
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        
        vector<string> ans;
        string a;
        res(a,0,s.size(),ans,s,0);
        
        return ans;
    }
};