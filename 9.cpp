class Solution {
public:
    bool isPalindrome(int n) {
        
        string s;
        
        if(n<0) return false;
        if(n==0) return true;
        
        while(n){
            s += (n%10+'0');
            n/=10;
        }
        
        int i=0,j=s.length()-1;
        
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};