class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxElement = nums[0];
        int currLength = 0;
        int maxLength = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] > maxElement) {
                maxElement = nums[i];
                currLength = 1;  
                maxLength = 1;   
            } else if (nums[i] == maxElement) {
                currLength++;   
                maxLength = max(currLength, maxLength);  
            } else {
                currLength = 0; 
            }
        }

        return maxLength;
    }
};
