class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& a) {
        
        int n = a.size();
        
        stack<int> st;
        vector<int> res(n);
        
        res[n-1] = 0;
        st.push(n-1);          // index push
        
        for(int i = n-2; i >= 0; i--) {
            
            // Remove all days which are not warmer
            while(!st.empty() && a[st.top()] <= a[i]) {
                st.pop();
            }
            
            // If no warmer day exists
            if(st.empty())
                res[i] = 0;
            
            else
                // Difference between indices
                res[i] = st.top() - i;
            
            // Push current index
            st.push(i);
        }
        
        return res;
    }
};