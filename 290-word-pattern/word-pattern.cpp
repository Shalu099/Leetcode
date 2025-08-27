class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }

        if (pattern.size() != words.size()) return false;

        unordered_map<char, string> mp1;   // pattern -> word
        unordered_map<string, char> mp2;   // word -> pattern

        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];

            if (mp1.count(c) && mp1[c] != w) return false;
            if (mp2.count(w) && mp2[w] != c) return false;

            mp1[c] = w;
            mp2[w] = c;
        }

        return true;
    }
};
