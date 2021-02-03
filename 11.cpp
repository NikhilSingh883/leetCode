class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        int water = 0;
        
        int i=0,j=n-1;
        
        while(i<=j){
            
            int a = min(h[i],h[j])*(j-i);
            water = max(a,water);
            
            if(h[i]>h[j]) j--;
            else i++;
            
        }
        
        return water;
    }
};