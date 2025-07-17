class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> result;
        string path = "";

        vector<string> phoneMap = {
            "",     "",     "abc",  "def", "ghi",
            "jkl",  "mno",  "pqrs", "tuv", "wxyz"
        };

        function<void(int)> backtrack = [&](int index) {
            if (index == digits.size()) {
                result.push_back(path);
                return;
            }

            string letters = phoneMap[digits[index] - '0'];
            for (char ch : letters) {
                path.push_back(ch);
                backtrack(index + 1);
                path.pop_back();
            }
        };

        backtrack(0);
        return result;
    }
};
