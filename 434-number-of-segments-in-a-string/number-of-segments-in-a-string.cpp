class Solution {
public:
    int countSegments(string s) {
        string temp="";
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                temp += s[i];
            }
            else if(temp.size()!=0){
                count++;
                temp="";
            }
        }
        if(temp.size()!=0){count++;}

        return count;
        
    }
};