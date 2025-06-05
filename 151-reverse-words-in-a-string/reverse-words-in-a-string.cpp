class Solution {
public:
    string reverseWords(string s) {
        int left = 0, right = s.length() - 1;

        // Trim leading spaces
        while (left <= right && s[left] == ' ') left++;

        // Trim trailing spaces
        while (right >= left && s[right] == ' ') right--;

        string temp = "", ans = "";

        while (left <= right) {
            char ch = s[left];

            if (ch != ' ') {
                temp += ch;
            } else if (ch == ' ') {
                // Only add word if temp is not empty (skip multiple spaces)
                if (!temp.empty()) {
                    if (!ans.empty()) ans = temp + " " + ans;
                    else ans = temp;
                    temp = "";
                }
            }
            left++;
        }

        // Add the last word
        if (!temp.empty()) {
            if (!ans.empty()) ans = temp + " " + ans;
            else ans = temp;
        }

        return ans;
    }
};
