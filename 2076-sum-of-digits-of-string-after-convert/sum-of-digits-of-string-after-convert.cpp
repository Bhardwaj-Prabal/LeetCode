class Solution {
public:
    int getLucky(string s, int k) {
        
       int n=s.size();
    string temp="";
       for(int i=0;i<n;i++){
            temp+= to_string(s[i]-'a'+1);
       }
       cout<<temp;
        int sum=0;
       while(k>0){
            
            int size=temp.size();
            int i=0;
            while(i<size){
                sum+= (int)(temp[i]) -48;
                i++;
            }
            k--;
            temp=to_string(sum);
            sum=0;
       }
        return stoi(temp);
    }
};