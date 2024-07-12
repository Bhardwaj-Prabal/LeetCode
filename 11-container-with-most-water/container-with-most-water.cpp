class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;

        int max_till = 0;

        while (left < right) {
            int volume = min(height[left], height[right]) * (right - left);
            max_till = max(volume, max_till);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return max_till;
    }
};
