class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        if (strs.empty())
            return {};

        unordered_map<string, vector<string>> mp;

        vector<int> count(26);

        for (string &s : strs) {

            fill(count.begin(), count.end(), 0);

            for (char c : s) {
                count[c - 'a']++;
            }

            string key = "";

            for (int i = 0; i < 26; i++) {
                key += "#";
                key += to_string(count[i]);
            }

            mp[key].push_back(s);
        }

        vector<vector<string>> ans;

        for (auto &it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};