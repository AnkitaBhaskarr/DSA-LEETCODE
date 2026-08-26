class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        int n = s.size();

        // Stack stores {character, count}
        stack<pair<char, int>> st;

        for (int i = 0; i < n; i++) {
            
            char c = s[i];

            // If stack is not empty and top character is same
            if (!st.empty() && st.top().first == c) {
                
                // Increase the count
                st.top().second++;

                // If count becomes k, remove it
                if (st.top().second == k) {
                    st.pop();
                }
            }
            else {
                
                // New character, push with count 1
                st.push({c, 1});
            }
        }

        // Result string
        string res = "";

        // Stack contains the remaining characters
        while (!st.empty()) {
            
            pair<char, int> p = st.top();
            st.pop();

            // Add character 'count' times
            while (p.second--) {
                res.push_back(p.first);
            }
        }

        // Since stack gives reverse order, reverse the answer
        reverse(res.begin(), res.end());

        return res;
    }
};