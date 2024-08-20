class Solution {
public:
    
    int pileCount;
    int memo[2][101][101]; 
    
    int findMaxStones(vector<int>& piles, int player, int index, int M) {
        
        if(index >= pileCount)
            return 0;
        
        if(memo[player][index][M] != -1)
            return memo[player][index][M];
        
        int bestResult = (player == 1) ? -1 : INT_MAX;
        int stonesCollected = 0;
        
        for(int x = 1; x <= min(2*M, pileCount-index); x++) {
            stonesCollected += piles[index + x - 1];
            
            if(player == 1) { // alice
                bestResult = max(bestResult, stonesCollected + findMaxStones(piles, 0, index + x, max(M, x)));
            } else { // bob
                bestResult = min(bestResult, findMaxStones(piles, 1, index + x, max(M, x)));
            }
        }
        
        return memo[player][index][M] = bestResult;
    }
    
    int stoneGameII(vector<int>& piles) {
        pileCount = piles.size();
        memset(memo, -1, sizeof(memo));
        
        return findMaxStones(piles, 1, 0, 1);
    }
};
