class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j = 0; // Position to place the next non-zero element

        // Move all non-zero elements to the front
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }

        // Fill the rest with zeroes
        while (j < n) {
            nums[j++] = 0;
        }
    }
};
