class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int  n=queries.size();
        vector<int> res;
        for(int i=0;i<n;i++){
            int temp=0;
            for(int j=queries[i][0];j<=queries[i][1];j++){
                temp ^=arr[j];
            }
            res.push_back(temp);
        }

        return res;
    }
};