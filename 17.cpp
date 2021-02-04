class Solution {
public:
    map<int,string> key;
    vector<string> ans;
    
    void generateALl(int i,string A,string str){
        if( i == A.size() ){
            ans.push_back(str);
            return;
        }

        for(auto x:key[A[i]-'0'])
            generateALl(i+1,A,str+x);

    }
    
    vector<string> letterCombinations(string digits) {
        
        int n = digits.size();
        if(n==0) return {};
        
        key[0]='0';
        key[1]='1';
        key[2] ="abc";
        key[3] ="def";
        key[4] ="ghi";
        key[5] ="jkl";
        key[6] ="mno";
        key[7] ="pqrs";
        key[8] ="tuv";
        key[9] ="wxyz";

        ans.clear();

        generateALl(0,digits,"");
        return ans;
    }
};

