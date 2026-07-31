class Solution {
public:
    bool isAnagram(string s, string t) {

        // If lengths are different, they can't be anagrams
        if (s.length() != t.length()) {
            return false;
        }

        // Create an array to count character frequencies
        vector<int> charCounts(26, 0);

        // Increment count for each character in 's'
        // Decrement count for each character in 't'
        for (int i = 0; i < s.length(); i++) {
            charCounts[s[i] - 'a']++;
            charCounts[t[i] - 'a']--;
        }

        // Check if all counts are zero
        for (int count : charCounts) {
            if (count != 0) {
                return false;
            }
        }

        // All counts are zero, so 't' is an anagram of 's'
        return true;
    }
};