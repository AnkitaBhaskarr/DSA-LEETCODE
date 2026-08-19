class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int n = nums.size();

        int zero = 0;
        int one = 0;
        int res = 0;

        // Hash map:
        // diff -> first index where this diff occurred
        unordered_map<int, int> f;

        // diff = 0 exists before array starts
        f[0] = -1;

        for (int i = 0; i < n; i++) {

            // Count 0s and 1s
            if (nums[i] == 0)
                zero++;
            else
                one++;

            // Difference between number of 0s and 1s
            int diff = zero - one;

            // If diff becomes 0,
            // number of 0s = number of 1s
            if (diff == 0) {
                res = max(res, i + 1);
                continue;
            }

            // If same diff was already present,
            // the subarray between the previous index and i
            // has equal number of 0s and 1s
            if (f.find(diff) == f.end()) {
                
                // Store only the first occurrence
                f[diff] = i;
            }
            else {
                
                int idx = f[diff];

                // Length of the balanced subarray
                int len = i - idx;

                res = max(len, res);
            }
        }

        return res;
    }
};