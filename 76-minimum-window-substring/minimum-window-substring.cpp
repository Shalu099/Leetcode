class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        // Frequency map for characters in t
        vector<int> targetFreq(256, 0);
        for (char c : t) {
            targetFreq[c]++;
        }

        vector<int> windowFreq(256, 0);
        int required = t.size();  // total characters needed (including duplicates)
        int formed = 0;           // how many matched so far

        int left = 0, minLen = INT_MAX, start = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            windowFreq[c]++;

            if (targetFreq[c] > 0 && windowFreq[c] <= targetFreq[c]) {
                formed++;
            }

            while (formed == required) {
                // Update the answer
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Try to shrink the window
                char leftChar = s[left];
                windowFreq[leftChar]--;
                if (targetFreq[leftChar] > 0 && windowFreq[leftChar] < targetFreq[leftChar]) {
                    formed--;
                }
                left++;
            }
        }

        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};
