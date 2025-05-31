class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count;

        for (int i = 0; i < n; i++) {
            count = 0;
            for (int j = 0; j < n; j++) {
                if (nums[i] == nums[j])
                    count++;
            }
            if (count > n / 2) {
                return nums[i];
            }
        }

        return -1; // This line ensures function always returns (although LeetCode guarantees a majority element exists)
    }
};
