class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>()); // Descending sort
        return nums[k - 1];
    }
};