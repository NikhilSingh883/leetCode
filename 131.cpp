class Solution {
public:
    vector<vector<string>> ans;
    bool isPal(string s,int st,int en){
        while(st<en)
            if(s[st++] != s[en--]) return false;
        return true;
    }
    
    void palPar(string& s, int index,  vector<string>& contri, int end){
        if(index > end){
            ans.push_back(contri);
            return;
        }
        string temp="";
        for(int i=index;i<=end;i++){
            temp+=s[i];
            if(isPal(s,index,i)){
                contri.push_back(temp);
                palPar(s,i+1,contri,end);
                contri.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        int n = s.size();
        ans.clear();
        vector<string> con;
        palPar(s,0,con,n-1);
        return ans;
    }
};