class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        unordered_map<int, int> cash;  

        for(int i = 0; i < n; i++) {
            if (bills[i] == 5) {
                cash[5]++; 
            } 
            else if (bills[i] == 10) {
                if (cash[5] == 0) return false; 
                cash[5]--;  
                cash[10]++;  
            } 
            else { 
                if (cash[10] > 0 && cash[5] > 0) {  
                    cash[10]--;
                    cash[5]--;
                    cash[20]++;
                } 
                else if (cash[5] >= 3) {  
                    cash[5] -= 3;
                    cash[20]++;
                } 
                else {
                    return false;  
                }
            }
        }
        return true;
    }
};
