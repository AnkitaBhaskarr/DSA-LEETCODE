#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int operations = 0;

        for (int x : nums) {
            int need = k - x;

            if (freq[need] > 0) {
                // Pair found
                freq[need]--;
                operations++;
            } else {
                // Store current number
                freq[x]++;
            }
        }

        return operations;
    }
};
