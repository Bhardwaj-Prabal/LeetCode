class Solution {
public:
    int length;
    vector<vector<int>> memo;

    int findMinTurns(int left, int right, string& str) {
        if(left == right)
            return 1;

        if(left > right)
            return 0;

        if(memo[left][right] != -1)
            return memo[left][right];

        int next = left + 1;
        while(next <= right && str[next] == str[left])
            next++;

        if(next == right + 1)
            return 1;

        int minTurnsWithoutMerge = 1 + findMinTurns(next, right, str);
        int minTurnsWithMerge = INT_MAX;

        for(int j = next; j <= right; j++) {
            if(str[left] == str[j]) {
                int mergeCost = findMinTurns(next, j - 1, str) + findMinTurns(j, right, str);
                minTurnsWithMerge = min(minTurnsWithMerge, mergeCost);
            }
        }

        return memo[left][right] = min(minTurnsWithMerge, minTurnsWithoutMerge);
    }

    int strangePrinter(string str) {
        length = str.length();
        memo.resize(length, vector<int>(length + 1, -1));
        return findMinTurns(0, length - 1, str);
    }
};
