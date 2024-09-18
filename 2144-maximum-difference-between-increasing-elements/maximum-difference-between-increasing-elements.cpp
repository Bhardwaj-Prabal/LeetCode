class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxTill=0;
        int n=nums.size();
        for(int i=0;i<n;i++){

            for(int j=i+1;j<n;j++){
                if(nums[j]-nums[i]>0){
                    maxTill=max(maxTill,nums[j]-nums[i]);
                }
                
            }
        }
        return maxTill>0 ? maxTill:-1;
    }
};