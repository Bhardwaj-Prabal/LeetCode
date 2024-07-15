class Solution {
public:
    bool isAnagram(string s, string t) {\
        if(s.size()!=t.size()){
            return false;
        }
        unordered_map<char,int> word1;
        unordered_map<char,int> word2;
        for(int i=0;i<s.size();i++){
            word1[s[i]]++;
        }
         for(int i=0;i<s.size();i++){
            word2[t[i]]++;
        }
        for(const auto &pairs: word1){
            char character=pairs.first;
            if(word2.find(character)==word2.end() || word2[character]!=word1[character]){
                return false;
            }
        }
        return true;
    }
};