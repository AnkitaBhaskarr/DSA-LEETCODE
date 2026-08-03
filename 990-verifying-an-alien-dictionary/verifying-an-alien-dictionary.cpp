class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {

        unordered_map<char, int> orderMap;

        // Store the position of each character
        for (int i = 0; i < order.length(); i++) {
            orderMap[order[i]] = i;
        }

        // Compare every adjacent pair of words
        for (int i = 0; i < words.size() - 1; i++) {

            for (int j = 0; j < words[i].length(); j++) {

                // Case: next word is shorter but same prefix
                if (j >= words[i + 1].length()) {
                    return false;
                }

                // If characters are different
                if (words[i][j] != words[i + 1][j]) {

                    int currLetter = orderMap[words[i][j]];
                    int nextLetter = orderMap[words[i + 1][j]];

                    if (nextLetter < currLetter) {
                        return false;
                    } else {
                        break;
                    }
                }
            }
        }

        return true;
    }
};