class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        
        // Convert each person's language list into a set for quick lookup
        vector<unordered_set<int>> personLang(m+1);
        for(int i=0; i<m; i++) {
            for(int lang : languages[i]) {
                personLang[i+1].insert(lang);
            }
        }

        // Step 1: Find invalid friendships
        unordered_set<int> candidates;
        for(auto& f : friendships) {
            int u = f[0], v = f[1];
            bool ok = false;
            for(int lang : personLang[u]) {
                if(personLang[v].count(lang)) {
                    ok = true;
                    break;
                }
            }
            if(!ok) { // invalid friendship
                candidates.insert(u);
                candidates.insert(v);
            }
        }

        if(candidates.empty()) return 0; // no need to teach anyone

        // Step 2: For each language, count how many candidates already know it
        vector<int> count(n+1, 0);
        for(int person : candidates) {
            for(int lang : personLang[person]) {
                count[lang]++;
            }
        }

        // Step 3: Find the language with max coverage
        int maxKnown = 0;
        for(int lang=1; lang<=n; lang++) {
            maxKnown = max(maxKnown, count[lang]);
        }

        return candidates.size() - maxKnown;
    }
};
