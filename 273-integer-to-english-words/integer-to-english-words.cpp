class Solution {
public:
    vector<string> units{"Zero", "One", "Two", "Three", "Four", "Five",
                         "Six", "Seven", "Eight", "Nine", "Ten", "Eleven",
                         "Twelve", "Thirteen", "Fourteen", "Fifteen",
                         "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    
    vector<string> tens{"", "", "Twenty", "Thirty", "Forty", "Fifty",
                        "Sixty", "Seventy", "Eighty", "Ninety"};
    
    vector<string> thousands{"", "Thousand", "Million", "Billion"};
    
    string numberToWords(int num) {
        if (num == 0) return units[num];
        string result;
        int i = 0;
        while (num > 0) {
            if (num % 1000 != 0) {
                result = helper(num % 1000) + (thousands[i].empty() ? "" : " " + thousands[i]) + (result.empty() ? "" : " " + result);
            }
            num /= 1000;
            i++;
        }
        return result;
    }
    
    string helper(int num) {
        if (num == 0) return "";
        if (num < 20) return units[num];
        if (num < 100) return tens[num / 10] + (num % 10 ? " " + units[num % 10] : "");
        return units[num / 100] + " Hundred" + (num % 100 ? " " + helper(num % 100) : "");
    }
};
