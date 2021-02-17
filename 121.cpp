class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        if(n==0)
            return 0;
        int k=1;
        
    int profit[k + 1][n + 1]; 

    for (int i = 0; i <= k; i++) 
        profit[i][0] = 0; 

    for (int j = 0; j <= n; j++) 
        profit[0][j] = 0; 

    for (int i = 1; i <= k; i++) { 
        int prevDiff = INT_MIN; 
        for (int j = 1; j < n; j++) { 
            prevDiff = max(prevDiff, 
                           profit[i - 1][j - 1] - prices[j - 1]); 
            profit[i][j] = max(profit[i][j - 1], 
                               prices[j] + prevDiff); 
        } 
    } 
  
    return profit[k][n - 1]; 
    }
};