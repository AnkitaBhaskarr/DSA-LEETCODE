#include <string>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        string result;
        
        for (char c : s) {
            if (c == '*') {
                result.pop_back();   // remove closest left character
            } else {
                result.push_back(c);
            }
        }
        
        return result;
    }
};
