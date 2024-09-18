class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.size();
        if(n<10) return {};

        string currStr="";
        unordered_map<string,pair<bool,bool>> mp;
        vector<string> result;
        int j=0;

        while(j<=n-10){
            currStr=s.substr(j,10);

            if(mp[currStr].first==false){
                mp[currStr].first=true;
                mp[currStr].second=false;
            }else{
                if(mp[currStr].second==false){
                    result.push_back(currStr);
                    mp[currStr].second=true;
                    }
            }
            j++;
        }

        return result;
    }
};