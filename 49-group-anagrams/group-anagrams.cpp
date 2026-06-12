#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string &s : strs) {
            vector<int> freq(26, 0);

            for (char c : s)
                freq[c - 'a']++;

            string key;
            for (int cnt : freq)
                key += to_string(cnt) + "#";

            mp[key].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto &p : mp)
            ans.push_back(p.second);

        return ans;
    }
};