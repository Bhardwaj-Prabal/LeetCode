class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        double maxAvg = -DBL_MAX;
        double currSum = 0;
        int n = nums.size();

        while (j < n) {
            currSum += nums[j];
            if (j - i + 1 == k) {
                maxAvg = max(currSum / k, maxAvg);
                currSum -= nums[i];
                i++;
            }
            j++;
        }
        return maxAvg;
    }
};
