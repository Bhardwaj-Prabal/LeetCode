class Solution {
public:
    bool isSubsequence(string s, string t) {

        int size=s.size();
        int ptr1=0;
        int ptr2=0;

        if(s.size()==0){
            return true;
        }

        if(t.size()==0){
            return false;
        }

        while(ptr1!=s.size()){
            if(ptr1==s.size() && ptr2!=t.size()){
                return false;
            }
            if(ptr2==t.size() && ptr1!=s.size()){
                return false;
            }

            if(s[ptr1]==t[ptr2]){
                ptr1++;
                ptr2++;

            }
            else{
                ptr2++;
            }
        }

        return true;

    }
};