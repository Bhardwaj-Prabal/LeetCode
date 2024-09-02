class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n=chalk.size();
        vector<long long > sum(n,0);
        sum[0]=chalk[0];
        for(int i=1;i<n;i++){
            sum[i]= sum[i-1] + chalk[i];
        }

        long long  temp=sum[n-1];

        if(temp<k){
            while(temp<k){
                k -= temp;
            }
        }
        int i=0;
        
        if(n==1) return 0;

        while(k!=0){
            i= i% n;
            
            k = k- chalk[i];
            if(k<0) return i%n;
            else{
                i++;
            }

            

        }

        return i%n;


    }
};