class Solution {
    int dp[201][201];
public:

    long long int solve(int i, int j, int n, int m, vector<vector<int>>& grid) {
        // If out of bounds
        if (i >= n || j >= m) return INT_MAX;
        // If reaching the bottom-right corner
        if (i == n - 1 && j == m - 1) return grid[i][j];

        if(dp[i][j]!= -1) return dp[i][j];
        // Move down or right and choose the minimum path
        long long int down = grid[i][j] + solve(i + 1, j, n, m, grid);
        long long int right = grid[i][j] + solve(i, j + 1, n, m, grid);

        return dp[i][j]=min(down, right);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(0, 0, n, m, grid);
    }
};
