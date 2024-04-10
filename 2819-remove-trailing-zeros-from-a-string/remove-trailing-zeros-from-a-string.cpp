class Solution {
public:
    string removeTrailingZeros(string num) {

        for(int i=num.size()-1;i>=0;i--){
            if(num[i]=='0'){
                num.erase(num.end()-1);
            }
            else{
                return num;
                break;
            }
        }
        return num;
    }
};