class Solution {
public:
    bool isPalindrome(string s) {
        
        string filtered;
        for (char c : s) {
            if (isalnum(c)) {
                filtered += tolower(c);
            }
        }
        int low = 0;
        int high = filtered.size() - 1;
        while (high > low) {
            if (filtered[low] != filtered[high]) return false;
            low++;
            high--;
        }

        return true;
    }
};