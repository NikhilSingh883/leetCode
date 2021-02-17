class Solution {
public:
    int maxProfit(vector<int>& price) 
    { 
    int n= price.size();
        int pro =0;
    if (n == 1) 
            return 0; 

        int i = 0; 
        while (i < n - 1) { 

            while ((i < n - 1) && (price[i + 1] <= price[i])) 
                i++; 

            if (i == n - 1) 
                break; 

            int buy = i++; 

            while ((i < n) && (price[i] >= price[i - 1])) 
                i++; 

            int sell = i - 1; 
            pro += price[sell] - price[buy]; 
        } 
        return pro;
    }
};