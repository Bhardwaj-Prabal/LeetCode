class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        priority_queue< pair<int,vector<int>>, vector<pair<int,vector<int>>>, greater<pair<int,vector<int>>> > pq;


        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                int dist=abs(i-rCenter)+abs(j-cCenter);
                vector<int> temp;
                temp.push_back(i);
                temp.push_back(j);
                pq.push(make_pair(dist,temp));
                }
        }
        vector<vector<int>> res;

        while(!pq.empty()){
            pair<int,vector<int>> top=pq.top();
            res.push_back(top.second);
            pq.pop();

        }
    return res;
        
    }
};