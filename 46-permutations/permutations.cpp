class Solution {
public:
    vector<vector<int>> ans;
    vector<int> current;
    vector<bool> used;

    void backtrack(vector<int>& nums) {
        if (current.size() == nums.size()) {
            ans.push_back(current);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue; // skip if already used
            used[i] = true;
            current.push_back(nums[i]);
            backtrack(nums);
            current.pop_back();   // backtrack
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        used.assign(nums.size(), false);
        backtrack(nums);
        return ans;
    }
};
