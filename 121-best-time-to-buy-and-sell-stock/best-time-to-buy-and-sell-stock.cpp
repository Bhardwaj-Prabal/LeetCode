class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        if(n==1) return 0;

        
        
        int minVal=prices[0];
        int maxDiff=prices[1]-prices[0];

        for(int i=1;i<n;i++){
            maxDiff=max(maxDiff,prices[i]-minVal);
            minVal=min(minVal,prices[i]);
        }
    return maxDiff>0 ? maxDiff : 0;
    }
};