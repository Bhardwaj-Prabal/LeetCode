class Solution {
public:
    int dp[201][201]; 
    
    int solve(int index, int row, vector<vector<int>>& triangle, int n) {
        if (row == n) return 0; 

        if (dp[row][index] != -1) return dp[row][index]; 

        int left = triangle[row][index] + solve(index, row + 1, triangle, n);
        int right = triangle[row][index + 1] + solve(index + 1, row + 1, triangle, n);


        return dp[row][index] = min(left, right);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        memset(dp, -1, sizeof(dp)); 
        return solve(0, 1, triangle, n) +triangle[0][0]; 
    }
};
