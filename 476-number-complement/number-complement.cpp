class Solution {
public:
    int findComplement(int num) {
        int bitmask = ~0;
        while (num & bitmask) {
            bitmask <<= 1;
        }
        return ~bitmask & ~num;
    }
};
