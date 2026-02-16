#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    
    struct VectorHash {
        size_t operator()(const vector<int>& v) const {
            size_t hash = 0;
            for (int num : v) {
                hash ^= std::hash<int>()(num) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
            }
            return hash;
        }
    };
    
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        
        unordered_map<vector<int>, int, VectorHash> rowMap;
        
        // Count all rows
        for (int i = 0; i < n; i++) {
            rowMap[grid[i]]++;
        }
        
        int result = 0;
        
        // Build and compare columns
        for (int col = 0; col < n; col++) {
            vector<int> column;
            for (int row = 0; row < n; row++) {
                column.push_back(grid[row][col]);
            }
            
            if (rowMap.count(column)) {
                result += rowMap[column];
            }
        }
        
        return result;
    }
};
