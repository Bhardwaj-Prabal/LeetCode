class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        priority_queue<pair<int,int>> big;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> small;

       int n=arrays.size();
       for(int i=0;i<n;i++){
        small.push(make_pair(arrays[i][0],i));
        int s=arrays[i].size();
        big.push(make_pair(arrays[i][s-1],i));
       }

        if(small.top().second==big.top().second){
            pair<int,int> big_1=big.top();
            pair<int,int> small_1=small.top();
            big.pop();
            small.pop();
           
            if(abs(big_1.first-small.top().first)< abs(big.top().first-small_1.first)){
                small.push(small_1);
                
            }else{
                big.push(big_1);
                
            }
        }
        return abs(small.top().first-big.top().first);
        }
};