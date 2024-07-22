class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return 1;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int count=0;
        int maxCount=0;
        for(auto pair:mp){
            if(mp.find(pair.first+1) !=mp.end()){
                count++;
                maxCount=max(count,maxCount);
            }else{
                count=0;
            }
        }
        return maxCount+1;
    }
};