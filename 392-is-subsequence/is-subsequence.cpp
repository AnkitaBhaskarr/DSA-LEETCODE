class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<int> pos[26];

        // Preprocess t
        for (int i = 0; i < t.size(); i++) {
            pos[t[i] - 'a'].push_back(i);
        }

        int prev = -1;
        for (char c : s) {
            auto &v = pos[c - 'a'];
            auto it = upper_bound(v.begin(), v.end(), prev);
            if (it == v.end()) return false;
            prev = *it;
        }
        return true;
    }
};