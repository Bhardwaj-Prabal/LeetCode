class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        int n=words.size();
        int m=allowed.size();
        int count=0;
        vector<int> charac(26,0);
        for(auto &c:allowed){
            charac[c-'a']++;
        }
        for(int i=0;i<n;i++){
            string temp=words[i];
            bool flag=false;
            for(int j=0;j<words[i].size();j++){
                if(charac[temp[j]-'a']){
                    flag=true;
                }else{
                    flag=false;
                    break;
                }
            }
            if(flag){
                count++;
            }
        }
        return count;
    }
};