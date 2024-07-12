#pragma optimize GCC("O3")
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int count = 0;
        sort(nums.begin(), nums.end()); // Sort the vector
        
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            int sum = nums[left] + nums[right];
            
            if (sum == k) {
                count++;
                left++;
                right--;
            } else if (sum < k) {
                left++;
            } else { // sum > k
                right--;
            }
        }
        
        return count;
    }
};