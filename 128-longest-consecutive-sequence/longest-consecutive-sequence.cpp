class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        int count=0;
        int maxCount=0;
        cout<<nums[0];
        for(int i=0;i<n-1;i++){

            if(nums[i]+1==nums[i+1]){
                count++;
                maxCount=max(count,maxCount);
            }else if(nums[i]==nums[i+1]){
                continue;
                
                }else{
                count=0;
            }
        }
        return maxCount+1;
    }
};