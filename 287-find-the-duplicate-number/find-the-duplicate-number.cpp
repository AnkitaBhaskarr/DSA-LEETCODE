class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // Slow moves one step
        int slow = nums[0];

        // Fast moves two steps
        int fast = nums[0];

        // First phase: find the meeting point
        do {
            slow = nums[slow];              // 1 step
            fast = nums[nums[fast]];        // 2 steps
        } while (slow != fast);

        // Second phase: find the starting point of the cycle
        slow = nums[0];

        while (slow != fast) {
            slow = nums[slow];              // 1 step
            fast = nums[fast];              // 1 step
        }

        // The meeting point is the duplicate number
        return slow;
    }
};