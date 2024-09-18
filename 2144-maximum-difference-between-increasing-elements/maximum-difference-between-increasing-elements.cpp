class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minEl=nums[0];
        int maxDiff=nums[1]-nums[0];

        for(auto &num:nums){
           
            maxDiff=max(maxDiff,num-minEl);
             minEl=min(num,minEl);
        }
        if(maxDiff<=0) return -1;
        return maxDiff;
    }
};