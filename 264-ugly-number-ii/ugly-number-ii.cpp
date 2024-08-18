class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglyNumbers(n + 1); 
        uglyNumbers[1] = 1;  
        
        int index2, index3, index5; 
        index2 = index3 = index5 = 1;
        
        for (int i = 2; i <= n; i++) {
            int nextMultipleOf2 = uglyNumbers[index2] * 2;
            int nextMultipleOf3 = uglyNumbers[index3] * 3;
            int nextMultipleOf5 = uglyNumbers[index5] * 5;
            
            uglyNumbers[i] = min({nextMultipleOf2, nextMultipleOf3, nextMultipleOf5});
            
            if (uglyNumbers[i] == nextMultipleOf2) {
                index2++;
            }
            if (uglyNumbers[i] == nextMultipleOf3) {
                index3++;
            }
            if (uglyNumbers[i] == nextMultipleOf5) {
                index5++;
            }
        }
        
        return uglyNumbers[n];
    }
};
