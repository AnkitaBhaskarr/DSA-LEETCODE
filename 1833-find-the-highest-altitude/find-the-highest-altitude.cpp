class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int current = 0;
        int maximum = 0;

        for (int g : gain) {
            current += g;
            maximum = max(maximum, current);
        }

        return maximum;
    }
};
