
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            int first = nums[i];
            int s = i + 1;
            int e = nums.size() - 1;

            while (s < e) {
                int total = first + nums[s] + nums[e];

                if (total == target) {
                    return total; // Found exact match
                }

                if (abs(total - target) < diff) {
                    diff = abs(total - target);
                    ans = total;
                }

                if (total > target)
                    e--;
                else
                    s++;
            }
        }

        return ans;
    }
};