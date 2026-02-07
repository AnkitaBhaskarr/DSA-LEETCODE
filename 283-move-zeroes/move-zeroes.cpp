#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int write = 0;

        // Move non-zero elements forward
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[write++] = nums[i];
            }
        }

        // Fill remaining positions with zero
        while (write < nums.size()) {
            nums[write++] = 0;
        }
    }
};
