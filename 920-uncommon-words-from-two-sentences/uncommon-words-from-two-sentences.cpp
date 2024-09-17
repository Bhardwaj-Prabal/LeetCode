class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> countMap1, countMap2;
        unordered_set<string> resultSet;
        
     
        countWords(s1, countMap1);
        countWords(s2, countMap2);
        
        for (const auto& [word, count] : countMap1) {
            if (count == 1 && countMap2.find(word) == countMap2.end()) {
                resultSet.insert(word);
            }
        }
        
        for (const auto& [word, count] : countMap2) {
            if (count == 1 && countMap1.find(word) == countMap1.end()) {
                resultSet.insert(word);
            }
        }

        return vector<string>(resultSet.begin(), resultSet.end());
    }
    
private:
    void countWords(const string& s, unordered_map<string, int>& countMap) {
        string temp;
        for (char ch : s) {
            if (ch == ' ') {
                if (!temp.empty()) {
                    countMap[temp]++;
                    temp="";
                }
            } else {
                temp += ch;
            }
        }
        if (!temp.empty()) {
            countMap[temp]++;
        }
    }
};
