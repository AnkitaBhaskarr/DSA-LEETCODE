class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(vector<int>& candidates, int target, int start,
               vector<int>& temp) {
        
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {

            // Same level par duplicate element skip karo
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            // Agar current number target se bada hai
            if (candidates[i] > target)
                break;

            temp.push_back(candidates[i]);

            // i + 1 because ek element sirf ek baar use hoga
            solve(candidates, target - candidates[i], i + 1, temp);

            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        // Duplicates ko easily handle karne ke liye sort
        sort(candidates.begin(), candidates.end());

        vector<int> temp;
        solve(candidates, target, 0, temp);

        return ans;
    }
};