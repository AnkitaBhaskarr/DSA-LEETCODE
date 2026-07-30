class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        // Create a HashSet to store elements from the array
        unordered_set<int> seenNumbers;

        // Iterate through each element in the array
        for (int num : nums) {

            // Check if the element is already in the HashSet
            if (seenNumbers.find(num) != seenNumbers.end()) {
                return true;   // Duplicate found
            }

            // Add the element to the HashSet
            seenNumbers.insert(num);
        }

        return false;   // No duplicates found
    }
};