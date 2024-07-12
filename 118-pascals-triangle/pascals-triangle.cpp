class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        triangle.push_back({1});
        
        if (numRows==1){
            return triangle ;
            
        }
        triangle.push_back({1,1});
        for(int i=2;i<numRows;i++){
            vector<int> temp(i+1);
            temp[0]=1;
            temp[i]=1;
            for(int k=1;k<i;k++){
                temp[k]=triangle[i-1][k-1]+triangle[i-1][k];
            }
            triangle.push_back(temp);
        }
        return triangle;
    }
};