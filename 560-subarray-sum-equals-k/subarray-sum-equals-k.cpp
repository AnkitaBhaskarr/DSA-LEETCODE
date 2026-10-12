class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long long, int> freq;

        freq[0] = 1;

        long long prefixSum = 0;
        int count = 0;

        for(int i=0; i<nums.size(); i++) {
            prefixSum += nums[i];

            long long required = prefixSum - k;

            count += freq[required];

            freq[prefixSum]++;
        }
        return count;
        
    }
};