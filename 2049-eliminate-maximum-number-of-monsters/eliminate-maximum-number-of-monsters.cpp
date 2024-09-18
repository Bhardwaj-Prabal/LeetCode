class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> timeToReach(n);
        for (int i = 0; i < n; i++) {
            timeToReach[i] = (dist[i] + speed[i] - 1) / speed[i];
        }
        
        sort(timeToReach.begin(), timeToReach.end());
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (timeToReach[i] > i) {
                res++;
            } else {
                break;
            }
        }
        
        return res;
    }
};