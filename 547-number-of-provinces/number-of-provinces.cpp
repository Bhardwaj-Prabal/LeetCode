class Solution {
public:

    void dfsRec(vector<vector<int>> &isConnected,vector<bool> &visited,int start){
        visited[start]=true;

        for(int i=0;i<isConnected[start].size();i++){
            if(isConnected[start][i]==1 && visited[i]==false){
                dfsRec(isConnected,visited,i);
            }
        }


    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size(), false);
        int count=0;
        for(int k=0;k<visited.size();k++){
            if(visited[k]==false){
                dfsRec(isConnected,visited,k);
                count++;
            }
        }
        return count;
    }
};