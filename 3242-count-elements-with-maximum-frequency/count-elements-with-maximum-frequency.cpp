class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        
        // Step 1: Count frequency
        for (int num : nums) {
            freq[num]++;
        }
        
        // Step 2: Find maximum frequency
        int maxFreq = 0;
        for (auto &p : freq) {
            maxFreq = max(maxFreq, p.second);
        }
        
        // Step 3: Count total elements with max frequency
        int result = 0;
        for (auto &p : freq) {
            if (p.second == maxFreq) {
                result += p.second;
            }
        }
        
        return result;
    }
};
