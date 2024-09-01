class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int p=original.size();

        if(m*n!=p) return {};
       
        vector<vector<int>> result(m, vector<int>(n,0));
        int k=0;


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(k<p){
                    result[i][j]=original[k];
                }
                k++;
            }
        }
        return result;
    }
};