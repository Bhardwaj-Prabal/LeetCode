class Solution {
    int dp[101][101];
public:
    int solve(int i,int j,int n,int m,vector<vector<int>>& obstacleGrid){
        if(i>n-1 || j>m-1) return 0;

        if(i==n-1 && j==m-1 && obstacleGrid[i][j]!=1) return 1;

        if(obstacleGrid[i][j]==1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int down=solve(i+1,j,n,m,obstacleGrid);
        int right= solve(i,j+1,n,m,obstacleGrid);

        return dp[i][j]=down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        memset(dp,-1,sizeof(dp));

        return solve(0,0,n,m,obstacleGrid);

        
    }
};