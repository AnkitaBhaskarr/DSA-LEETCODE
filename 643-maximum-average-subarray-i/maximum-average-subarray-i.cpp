#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // Compute sum of first k elements
        long long windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }

        long long maxSum = windowSum;

        // Slide the window
        for (int i = k; i < nums.size(); i++) {
            windowSum += nums[i] - nums[i - k];
            maxSum = max(maxSum, windowSum);
        }

        // Return maximum average
        return static_cast<double>(maxSum) / k;
    }
};
