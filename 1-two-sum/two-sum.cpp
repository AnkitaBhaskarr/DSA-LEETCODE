class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // Create a HashMap to store numbers and their indices
        unordered_map<int, int> map;

        // Iterate through the array
        for (int i = 0; i < nums.size(); i++) {

            // Calculate the complement of the current number
            int complement = target - nums[i];

            // Check if the complement is already in the map
            if (map.find(complement) != map.end()) {

                // If found, return the indices of the complement and the current number
                return {map[complement], i};
            }

            // Otherwise, add the current number and its index to the map
            map[nums[i]] = i;
        }

        // Return an empty array if no solution is found (this case won't occur as per problem constraints)
        return {};
    }
};