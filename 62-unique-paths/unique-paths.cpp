class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>> &dp) {
        // Base case: if out of bounds, return 0
        if (i >= m || j >= n) return 0;
        
        // Base case: if reached the bottom-right corner, return 1
        if (i == m - 1 && j == n - 1) return 1;
        
        // If already computed, return the stored result
        if (dp[i][j] != -1) return dp[i][j];
        
        // Move down and right
        int down = solve(i + 1, j, m, n, dp);
        int side = solve(i, j + 1, m, n, dp);
        
        // Store and return the result
        return dp[i][j] = down + side;
    }

    int uniquePaths(int m, int n) {
        // Initialize the dp table with -1
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, m, n, dp);
    }
};
