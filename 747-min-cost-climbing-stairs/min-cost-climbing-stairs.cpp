class Solution {
public:
    int MinCost(int index, const vector<int>& cost, int n, vector<int>& dp) {
        // Base case: If index is out of bounds, no cost
        if (index >= n) {
            return 0;
        }

        // Check if result is already computed
        if (dp[index] != -1) {
            return dp[index];
        }

        // Compute the cost for taking 1 step or 2 steps
        int take_1 = cost[index] + MinCost(index + 1, cost, n, dp);
        int take_2 = cost[index] + MinCost(index + 2, cost, n, dp);

        // Store the result in dp array
        dp[index] = min(take_1, take_2);

        return dp[index];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1); // Initialize dp array with -1

        // Compute the minimum cost starting from index 0 and index 1
        int index_0 = MinCost(0, cost, n, dp);
        int index_1 = MinCost(1, cost, n, dp);

        return min(index_0, index_1);
    }
};