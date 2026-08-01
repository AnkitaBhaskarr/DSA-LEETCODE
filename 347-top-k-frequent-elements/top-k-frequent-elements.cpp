class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        if (k == nums.size())
            return nums;

        unordered_map<int, int> count;

        // Count frequency of each element
        for (int num : nums) {
            count[num]++;
        }

        // Min Heap based on frequency
        auto cmp = [&](int a, int b) {
            return count[a] > count[b];
        };

        priority_queue<int, vector<int>, decltype(cmp)> heap(cmp);

        // Keep only k most frequent elements
        for (auto &it : count) {
            heap.push(it.first);

            if (heap.size() > k) {
                heap.pop();
            }
        }

        vector<int> ans;

        while (!heap.empty()) {
            ans.push_back(heap.top());
            heap.pop();
        }

        return ans;
    }
};