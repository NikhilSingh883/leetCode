class Solution {
public:
    string intToRoman(int n) {
        string s;
        string a[]={"IV","XL","CD","M"};
        int place = 0;
        while(n){
            int dig = n%10;
            if(dig<=3)
                while(dig--) s=a[place][0]+s;
            else if(dig==4){
                s=a[place][1]+s; s=a[place][0]+s;
            }
            else if(dig==5){
                s=a[place][1]+s;
            }
            else if(dig<9){
                dig-=5;
                while(dig--) s=a[place][0]+s;
                s=a[place][1]+s;
                
            }
            else if(dig==9)
            {
                s=a[place+1][0]+s;
                s=a[place][0]+s;
            }
            n/=10;
            place++;
        }
        return s;
        
    }
};