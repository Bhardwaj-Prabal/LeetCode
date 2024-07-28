class Solution {
public:

    bool checkUnique(unordered_map <char,int> &mp){
        for(auto & pair:mp){
            if(pair.second>1) return false;
        }

        return true;
    }
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp; 
        int i=0;
        int j=0;
        int n=s.size();

        if(n==0) return 0;
        if(n==1) return 1;
        int result=0;

        while(j<n){

            mp[s[j]]++;

            if(checkUnique(mp)){
                result++;
            }else{
                mp[s[i]]--;
                i++;
            }
            j++;
        }

        return result;
    }
};