class Solution {
public:

    int solve(vector<int>& prices, int fee, int index, bool invested, vector<vector<int>>& dp) {
        // Base case: If we are at the end of the prices array
        if (index == prices.size()) {
            return 0;
        }
        
        if (dp[index][invested] != -1) {
            return dp[index][invested];
        }

        int doNothing = solve(prices, fee, index + 1, invested, dp);

        if (invested) {
            // If currently invested, decide to sell
            int sell = prices[index] - fee + solve(prices, fee, index + 1, false, dp);
            dp[index][invested] = max(doNothing, sell);
        } else {
            // If not invested, decide to buy
            int buy = -prices[index] + solve(prices, fee, index + 1, true, dp);
            dp[index][invested] = max(doNothing, buy);
        }

        return dp[index][invested];
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(prices, fee, 0, false, dp);
    }
};
