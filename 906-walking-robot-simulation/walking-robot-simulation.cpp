class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int n = commands.size();
        vector<int> start {0, 0};
        vector<vector<int>> direction{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dirIndex = 0;
        int maxDist = 0;
        
        set<pair<int, int>> obstacleSet;
        for (const auto& obstacle : obstacles) {
            obstacleSet.insert({obstacle[0], obstacle[1]});
        }

        for (int i = 0; i < n; i++) {
            if (commands[i] == -1) {
                dirIndex = (dirIndex + 1) % 4;  // Right turn
            } else if (commands[i] == -2) {
                dirIndex = (dirIndex + 3) % 4;  // Left turn
            } else {
                for (int j = 0; j < commands[i]; j++) {
                    int newX = start[0] + direction[dirIndex][0];
                    int newY = start[1] + direction[dirIndex][1];
                    
                    if (obstacleSet.find({newX, newY}) != obstacleSet.end()) {
                        
                        break;
                    }
                   
                    start[0] = newX;
                    start[1] = newY;
                    
                    maxDist = max(maxDist, start[0] * start[0] + start[1] * start[1]);
                }
            }
        }
        return maxDist;
    }
};
