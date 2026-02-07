class Solution {
public:
    void reverseRange(string &s, int left, int right) {
        while (left < right) {
            swap(s[left++], s[right--]);
        }
    }

    void removeExtraSpaces(string &s) {
        int n = s.size();
        int slow = 0;

        for (int fast = 0; fast < n; fast++) {
            if (s[fast] != ' ') {
                // insert space before word if needed
                if (slow > 0) s[slow++] = ' ';
                while (fast < n && s[fast] != ' ')
                    s[slow++] = s[fast++];
            }
        }
        s.resize(slow);
    }

    string reverseWords(string s) {
        // 1. Remove extra spaces
        removeExtraSpaces(s);

        // 2. Reverse whole string
        reverseRange(s, 0, s.size() - 1);

        // 3. Reverse each word
        int start = 0;
        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') {
                reverseRange(s, start, i - 1);
                start = i + 1;
            }
        }

        return s;
    }
};
