#include <vector>
#include <unordered_map>
#include <cstdlib>
using namespace std;

class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> mp; // value -> index

public:
    RandomizedSet() {}

    bool insert(int val) {
        if (mp.count(val)) return false;

        nums.push_back(val);
        mp[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (!mp.count(val)) return false;

        int index = mp[val];
        int last = nums.back();

        // Move last element to index
        nums[index] = last;
        mp[last] = index;

        // Remove last element
        nums.pop_back();
        mp.erase(val);

        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }
};