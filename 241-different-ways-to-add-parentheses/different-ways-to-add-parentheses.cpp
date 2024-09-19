class Solution {
public:
    vector<int> compute(string expr) {
        vector<int> outcomes;

        for(int i = 0; i < expr.length(); i++) {
            if(expr[i] == '+' || expr[i] == '-' || expr[i] == '*') {
                vector<int> left = compute(expr.substr(0, i));
                vector<int> right = compute(expr.substr(i + 1));

                for(int &a : left) {
                    for(int &b : right) {
                        if(expr[i] == '+') {
                            outcomes.push_back(a + b);
                        } else if(expr[i] == '-') {
                            outcomes.push_back(a - b);
                        } else {
                            outcomes.push_back(a * b);
                        }
                    }
                }
            }
        }

        if(outcomes.empty()) {
            outcomes.push_back(stoi(expr));
        }

        return outcomes;
    }

    vector<int> diffWaysToCompute(string expression) {
        return compute(expression);
    }
};
