class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if (nums.size() == 0) {
            return 0;
        }

        unordered_set<int> numSet;

        for (int i = 0; i < nums.size(); i++) {
            numSet.insert(nums[i]);
        }

        int longestSub = 1;

        for (int num : numSet) {

            // If previous element exists, this is not the start
            if (numSet.count(num - 1)) {
                continue;
            }
            else {

                int currentNum = num;
                int currentSub = 1;

                while (numSet.count(currentNum + 1)) {
                    currentNum++;
                    currentSub++;
                }

                longestSub = max(longestSub, currentSub);
            }
        }

        return longestSub;
    }
};