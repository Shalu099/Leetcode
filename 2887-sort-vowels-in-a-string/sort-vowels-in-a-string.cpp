class Solution {
public:
    string sortVowels(string s) {
        vector<int> lower(26, 0);
        vector<int> upper(26, 0);
        vector<int> positions; // To store indices of vowels

        // Step 1: Count vowels and mark their positions
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                lower[c - 'a']++;
                positions.push_back(i);
            } else if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                upper[c - 'A']++;
                positions.push_back(i);
            }
        }

        // Step 2: Reconstruct sorted vowel string
        string sortedVowels;
        for (int i = 0; i < 26; i++) {
            char uc = 'A' + i;
            while (upper[i]--) sortedVowels += uc;
        }
        for (int i = 0; i < 26; i++) {
            char lc = 'a' + i;
            while (lower[i]--) sortedVowels += lc;
        }

        // Step 3: Replace original vowels with sorted vowels
        for (int i = 0; i < positions.size(); i++) {
            s[positions[i]] = sortedVowels[i];
        }

        return s;
    }
};













// class Solution {
// public:
//     string sortVowels(string s) {
//         vector<int> lower(26,0);
//         vector<int> upper(26,0);
//         for(int i=0;i<s.size();i++){
//             if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
//                     lower[s[i]-'a']++;
//             s[i]='#';
//             }else if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
//         upper[s[i]-'A']++;
//         s[i]='#';
           
//         }

//     }
//     string ans;
//     for(int i=0;i<26;i++){
//         char c='A'+i;
//         while(upper[i]){
//             ans+=c;
//             upper[i]--;
//         }
//     }
//      for(int i=0;i<26;i++){
//         char c='a'+i;
//         while(lower[i]){
//             ans+=c;
//             lower[i]--;
//         }
//     }
//     int first=0,second=0;
//     while(second<vowel.size()){
//         if(s[i]=='#')
//         {
//             s[i]=vowel[second];
//             second++;
//         }
//         first++;
//         return s;
//     }
// };