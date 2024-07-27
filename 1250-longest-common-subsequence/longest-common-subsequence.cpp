class Solution {
public:

    int solve(int i,int j, int m,int n ,string &text1,string &text2,vector<vector<int>> &dp){
        if(i==m || j==n ) return 0;

        if(text1[i]==text2[j]){
            return 1+ solve(i+1,j+1,m,n,text1,text2,dp);
        }

        if(dp[i][j]!= -1) return dp[i][j];

        int t1=solve(i+1,j,m,n,text1,text2,dp);
        int t2=solve(i,j+1,m,n,text1,text2,dp);
        return dp[i][j]=max(t1,t2);
    }


    int longestCommonSubsequence(string text1, string text2) {

    int m=text1.size();
    int n=text2.size();

    vector<vector<int>> dp(m,vector<int>(n,-1));

    return solve(0,0,m,n,text1,text2,dp);
    }
};