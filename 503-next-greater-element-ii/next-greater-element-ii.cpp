class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        
        // Answer array, initially -1
        vector<int> ans(n, -1);
        
        // Stack stores possible next greater elements
        stack<int> st;
        
        // Put elements before nums[n-1] in stack
        // because array is circular
        for (int i = n - 2; i >= 0; i--) {
            st.push(nums[i]);
        }
        
        // Traverse from last element to first
        for (int i = n - 1; i >= 0; i--) {
            
            // Remove all elements which are
            // smaller than or equal to current element
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }
            
            // If stack is not empty, top is the
            // next greater element
            if (!st.empty()) {
                ans[i] = st.top();
            }
            else {
                ans[i] = -1;
            }
            
            // Push current element for
            // the elements before it
            st.push(nums[i]);
        }
        
        return ans;
    }
};