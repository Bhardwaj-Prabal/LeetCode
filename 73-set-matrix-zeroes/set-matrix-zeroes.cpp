
#include <vector>
#include <unordered_set>
#include <utility> // for std::pair

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> zeroRows;
        unordered_set<int> zeroCols;

        // Identify rows and columns that need to be zeroed
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == 0) {
                    zeroRows.insert(i);
                    zeroCols.insert(j);
                }
            }
        }

        // Set rows to zero
        for (auto row : zeroRows) {
            for (int j = 0; j < matrix[row].size(); ++j) {
                matrix[row][j] = 0;
            }
        }

        // Set columns to zero
        for (auto col : zeroCols) {
            for (int i = 0; i < matrix.size(); ++i) {
                matrix[i][col] = 0;
            }
        }
    }
};
