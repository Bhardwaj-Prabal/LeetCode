class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n, 0);
        vector<int> rightSum(n, 0);
        int sum = nums[0];
        leftSum[0] = sum;


        for (int i = 1; i < n; i++) {
            sum += nums[i];
            leftSum[i] = sum;
        }

        sum = nums[n - 1];
        rightSum[n - 1] = sum; 

        for (int i = n - 2; i >= 0; i--) {
            sum += nums[i];
            rightSum[i] = sum;
        }


       for(int i=0;i<n;i++){
            if(leftSum[i]==rightSum[i]){
                return i;
            }
       }

       return -1;
      
    }
};