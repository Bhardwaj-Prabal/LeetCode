class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagramMap;
    for (string s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        anagramMap[key].push_back(s);
    }

    vector<vector<string>> res;
    for (auto& pair : anagramMap) {
        res.push_back(pair.second);
    }

    return res;
    }
};