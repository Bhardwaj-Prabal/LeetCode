class Solution {
public:
    string reversePrefix(string word, char ch) {

        for(int i=0;i<word.size();i++){
            if(word[i]==ch){
                int low=0;
                int high=i;
                while(high>low){
                    char temp=word[low];
                    word[low]=word[high];
                    word[high]=temp;
                    high--;
                    low++;
                }
                return word;
            }
            else{
                continue;
            }
        }
    return word;
    }
};