class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end()); // Rule 1

        unordered_map<string, string> caseInsensitive; // Rule 2
        unordered_map<string, string> vowelInsensitive; // Rule 3

        for (string &word : wordlist) {
            string lower = toLower(word);
            if (caseInsensitive.find(lower) == caseInsensitive.end())
                caseInsensitive[lower] = word;
            
            string devowel = maskVowels(lower);
            if (vowelInsensitive.find(devowel) == vowelInsensitive.end())
                vowelInsensitive[devowel] = word;
        }

        vector<string> result;
        for (string &query : queries) {
            if (exact.count(query)) { // Rule 1
                result.push_back(query);
            } else {
                string lower = toLower(query);
                if (caseInsensitive.count(lower)) { // Rule 2
                    result.push_back(caseInsensitive[lower]);
                } else {
                    string devowel = maskVowels(lower);
                    if (vowelInsensitive.count(devowel)) { // Rule 3
                        result.push_back(vowelInsensitive[devowel]);
                    } else {
                        result.push_back("");
                    }
                }
            }
        }
        return result;
    }

private:
    string toLower(const string &s) {
        string res = s;
        for (char &c : res) c = tolower(c);
        return res;
    }

    string maskVowels(const string &s) {
        string res = s;
        for (char &c : res) {
            if (isVowel(c)) c = '*';
        }
        return res;
    }

    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
