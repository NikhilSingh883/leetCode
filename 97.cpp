class Solution {
public:
    
    int dp[201][201];
    bool answ(string s1,int i,string s2,int j,string ans,string s3,int k)
    {   
        
        if(k==s3.length() and i==s1.length() and j==s2.length())
            return true;
        
        if(dp[i][j]!=-1) return dp[i][j];

        bool a=false;
                
        if(i<s1.length() && s3[k]==s1[i])
            a= a || answ(s1,i+1,s2,j,ans+s1[i],s3,k+1);
        
        if(j<s2.length() && s2[j]==s3[k])
            a= a || answ(s1,i,s2,j+1,ans+s2[j],s3,k+1);
        
        return dp[i][j] =a;
    }
    
    bool isInterleave(string s1, string s2, string s3)
    {   
        memset(dp,-1,sizeof dp);
        return answ(s1,0,s2,0,"",s3,0);
    }

};