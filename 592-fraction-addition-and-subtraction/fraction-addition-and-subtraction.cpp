class Solution {
public:
    int lcm(int a, int b) {
        return (a * b) / std::gcd(a, b);
    }
    
    bool isDigit(char a) {
        return a >= '0' && a <= '9';
    }

    string fractionAddition(string expression) {
        vector<int> numerators;
        vector<int> denominators;

        stack<char> st;
        int n = expression.size();

        for (int i = 0; i < n; ++i) {
            if (expression[i] == '-' || expression[i] == '+') {
                st.push(expression[i]);
            } else if (isDigit(expression[i])) {
                st.push(expression[i]);
            } else if (expression[i] == '/') {
                string numerator = "";
                while (!st.empty()) {
                    numerator = st.top() + numerator; 
                    st.pop();
                }

                numerators.push_back(stoi(numerator));

                string denominator = "";
                while (i + 1 < n && isDigit(expression[i + 1])) {
                    denominator += expression[++i]; 
                }

                denominators.push_back(stoi(denominator));
            }
        }

        int resLCM = denominators[0];
        for (size_t i = 1; i < denominators.size(); ++i) {
            resLCM = lcm(resLCM, denominators[i]);
        }

        int resNumerator = 0;
        for (size_t i = 0; i < numerators.size(); ++i) {
            resNumerator += numerators[i] * (resLCM / denominators[i]);
        }

        
        int gcd =std:: gcd(resNumerator, resLCM);
        resNumerator /= gcd;
        resLCM /= gcd;

        return to_string(resNumerator) + "/" + to_string(resLCM);
    }
};