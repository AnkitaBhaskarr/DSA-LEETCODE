class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;

        // Count occurrences
        for (int num : arr) {
            freq[num]++;
        }

        unordered_set<int> occurrences;

        // Check if frequencies are unique
        for (auto &it : freq) {
            if (occurrences.count(it.second)) {
                return false;
            }
            occurrences.insert(it.second);
        }

        return true;
    }
};