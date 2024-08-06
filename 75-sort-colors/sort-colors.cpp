class Solution {
public:
    void swap(int &num1, int &num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }

    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int j = n - 1;

        // First pass: Move all 2s to the end
        for (int i = 0; i <= j; ) {
            if (nums[i] == 2) {
                swap(nums[i], nums[j]);
                j--;
            } else {
                i++;
            }
        }

        // Second pass: Move all 1s to their correct place
        int k = 0;
        while (k <= j) {
            if (nums[k] == 1) {
                swap(nums[k], nums[j]);
                j--;
            } else {
                k++;
            }
        }
    }
};
