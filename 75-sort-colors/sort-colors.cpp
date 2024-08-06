class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> freq(3, 0);
        int n = nums.size();

        for (int num : nums) {
            freq[num]++;
        }
    
        int index = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < freq[i]; j++) {
                nums[index++] = i;
            }
        }
    }
};
