class Solution {
public:
    bool isPalindrome(int x) {

        string res=to_string(x);

        int low=0;
        int high=res.size()-1;

        while(high>low){
            if(res[low]==res[high]){
                low++;
                high--;
                continue;
            }
            else{
                return false;
            }
        }
        
    return true;
    }
};