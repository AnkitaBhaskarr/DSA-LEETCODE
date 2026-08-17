class Solution {
public:
    int subarraysDivByK(vector<int>& a, int k) {

        // Store frequency of each remainder
        unordered_map<int, int> f;

        // Remainder 0 is already present once
        f[0] = 1;

        int n = a.size();
        int ans = 0;
        int sum = 0;

        for (int i = 0; i < n; i++) {

            // Calculate prefix sum
            sum += a[i];

            // Find remainder
            int rem = sum % k;

            // Handle negative remainder
            if (rem < 0) {
                rem = rem + k;
            }

            // If same remainder appeared before,
            // the subarray between them is divisible by k
            ans += f[rem];

            // Increase frequency of this remainder
            f[rem]++;
        }

        return ans;
    }
};