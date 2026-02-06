#include <string>
using namespace std;
// ANKITA
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merged;
        int i = 0;

        while (i < word1.length() || i < word2.length()) {
            if (i < word1.length()) {
                merged += word1[i];
            }
            if (i < word2.length()) {
                merged += word2[i];
            }
            i++;
        }

        return merged;
    }
};
