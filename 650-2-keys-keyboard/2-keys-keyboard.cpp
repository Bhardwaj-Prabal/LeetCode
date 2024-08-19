class Solution {
public:
    int t[1001][1001];

    int solve(int count, int pasteLen, int n) {
        if (count == n) {
            return 0;
        }

        if (count > n) {
            return 1000;
        }

        if (t[count][pasteLen] != -1) {
            return t[count][pasteLen];
        }

        int copyPaste = 2 + solve(count + count, count, n);
        int paste = 1 + solve(count + pasteLen, pasteLen, n);

        return t[count][pasteLen] = min(copyPaste, paste);
    }

    int minSteps(int n) {
        if (n == 1) {
            return 0;
        }

        memset(t, -1, sizeof(t));
        return 1 + solve(1, 1, n);
    }
};
