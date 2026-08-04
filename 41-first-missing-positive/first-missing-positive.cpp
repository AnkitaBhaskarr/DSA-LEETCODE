class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        int n = nums.size();

        int contains = 0;

        // Check if 1 is present
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                contains++;
                break;
            }
        }

        if (contains == 0) {
            return 1;
        }

        // Replace invalid numbers with 1
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = 1;
            }
        }

        // Mark visited indices
        for (int i = 0; i < n; i++) {
            int a = abs(nums[i]);

            if (a == n) {
                nums[0] = -abs(nums[0]);
            }
            else {
                nums[a] = -abs(nums[a]);
            }
        }

        // Find first positive index
        for (int i = 1; i < n; i++) {
            if (nums[i] > 0) {
                return i;
            }
        }

        // Check for number n
        if (nums[0] > 0) {
            return n;
        }

        return n + 1;
    }
};