class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        vector<int> result(n, 1);

        int pre = 1;
        int post = 1;

        // Store prefix products
        for (int i = 0; i < n; i++) {
            result[i] = pre;
            pre *= nums[i];
        }

        // Multiply with postfix products
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= post;
            post *= nums[i];
        }

        return result;
    }
};