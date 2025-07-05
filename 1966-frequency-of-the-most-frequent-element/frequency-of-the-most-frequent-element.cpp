class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long left = 0, total = 0, result = 0;

        for (long long right = 0; right < nums.size(); ++right) {
            total += nums[right];

            while ((nums[right] * (right - left + 1)) - total > k) {
                total -= nums[left];
                ++left;
            }

            result = max(result, right - left + 1);
        }

        return result;
    }
};
