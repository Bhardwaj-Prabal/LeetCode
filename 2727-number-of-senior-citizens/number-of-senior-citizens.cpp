class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count=0;
        int n= details.size();

        for(int i=0;i<n;i++){
            string age= details[i];
            
            if(stoi(age.substr(11,2))> 60){
                count++;
            }
        }

        return count;
    }
};