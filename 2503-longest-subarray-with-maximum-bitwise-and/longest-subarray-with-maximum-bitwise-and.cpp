class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int maxLen = 0, currentLen = 0;

        for (int num : nums) {
            if (num == maxVal) {
                currentLen++;
                maxLen = max(maxLen, currentLen);
            } else {
                currentLen = 0;
            }
        }

        return maxLen;
    }
};
