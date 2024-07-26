class Solution {
public:
    int solve(int index, int amount, const std::vector<int>& coins, std::vector<std::vector<int>>& dp) {
        if (amount == 0) return 0; // No coins needed to make amount 0
        if (index >= coins.size() || amount < 0) return INT_MAX; // Out of bounds or negative amount
        
        if (dp[index][amount] != -1) return dp[index][amount];
        
        // Option 1: Take the coin
        int take = solve(index, amount - coins[index], coins, dp);
        if (take != INT_MAX) take++; // If take is not impossible, increase count

        // Option 2: Skip the coin
        int skip = solve(index + 1, amount, coins, dp);

        // Return the minimum of the two options
        return dp[index][amount] = std::min(take, skip);
    }

    int coinChange(const std::vector<int>& coins, int amount) {
        int n = coins.size();
        if (amount == 0) return 0; // No coins needed to make amount 0
        if (n == 0) return -1; // No coins available

        // Initialize a 2D DP array
        std::vector<std::vector<int>> dp(n, std::vector<int>(amount + 1, -1));

        int result = solve(0, amount, coins, dp);
        return result == INT_MAX ? -1 : result;
    }
};