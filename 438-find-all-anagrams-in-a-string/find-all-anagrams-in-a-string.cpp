class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int windowSize=p.size();
        int n=s.size();
        vector<int> result;
        int i=0;
        int j=0;
        vector<int> characters(26,0);
        vector<int> pCharacters(26,0);

        for(int i=0;i<windowSize;i++){
            pCharacters[p[i]-'a']++;
        }

        while(j<n){
            char curr =s[j];
            characters[curr-'a']++;

            if(j-i+1==windowSize){
                if(characters==pCharacters){    
                    result.push_back(i);
                }
                characters[s[i]-'a']--;
                i++;
                j++;
            }else{
                j++;

            }

        }
        return result;
        
    }
};