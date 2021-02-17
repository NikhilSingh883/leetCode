class Solution {
public:
    int f(int i, bool buyMode, vector<int> &prices, vector<vector<int> > &dp) {
        int n = prices.size();
        if (i >= n) {
            dp[i][buyMode] = 0;
            return 0;
        }
        if (dp[i][buyMode] != -1){
            return dp[i][buyMode];
        }
        if (buyMode) {
            //we are in buy mode
            //either skip buying today and remain in buy mode
            int skipToday = f(i + 1, true, prices, dp);

            //or buy today and turn into sell mode
            int buyToday = -prices[i] + f(i + 1, false, prices, dp);
            
            dp[i][buyMode] = max(skipToday, buyToday);
            return dp[i][buyMode];

        } else {
            //sellmode                        
            //either skip selling today but continue being in sell mode            
            int skipToday = f(i + 1, false, prices, dp);

            //or you sell today and book profit and are back in buy mode with cooldown
            int sellToday = prices[i] + f(i + 2, true, prices, dp);

            dp[i][buyMode] = max(sellToday, skipToday);
            return dp[i][buyMode];
        }
    }    
    
    int maxProfit(vector<int> &prices) {
        vector<vector<int> > dp( prices.size() + 5, vector<int>(2, -1));
        return f(0, true, prices, dp);
    }
};