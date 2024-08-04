class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long int> res;

        for(int i=0;i<n-1;i++){
            bool flag=false;
            long long int temp=nums[i];
            for(int j=i;j<n;j++){
                if(!flag){
                    res.push_back(nums[i]);
                    flag=true;
                    continue;
                } 
                temp+= nums[j];
                res.push_back(temp);
            }
        }
        res.push_back(nums[n-1]);
        sort(res.begin(),res.end());
        long long int result=0;
        for(int i=left-1;i<=right-1;i++){
            result += res[i];
        }
        return (result)%1000000007;

    }
};