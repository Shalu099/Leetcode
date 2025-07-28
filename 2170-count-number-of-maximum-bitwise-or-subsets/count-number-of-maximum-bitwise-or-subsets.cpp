class Solution {
public:
    int count = 0;
    int max_or = 0;

    void dfs(vector<int>& nums, int index, int curr_or) {
        if (index == nums.size()) {
            if (curr_or == max_or)
                count++;
            return;
        }
        dfs(nums, index + 1, curr_or | nums[index]);

        dfs(nums, index + 1, curr_or);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        
        for (int num : nums)
            max_or |= num;

        dfs(nums, 0, 0);

        return count;
    }
};
