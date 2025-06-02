class Solution {
public:
    string sortSentence(string s) {
        vector<string> ans(10);  // max 9 words
        string temp = "";
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                int pos = temp.back() - '0';
                temp.pop_back();
                ans[pos] = temp;
                temp.clear();
                count++;
            } else {
                temp += s[i];
            }
        }

        // Process the last word (after the last space)
        int pos = temp.back() - '0';
        temp.pop_back();
        ans[pos] = temp;
        count++;

        string result = "";
        for (int i = 1; i <= count; i++) {
            result += ans[i] + " ";
        }
        result.pop_back(); // remove trailing space
        return result;
    }
};
