#include <string>
#include <numeric> // for std::gcd

using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // Check if both strings are built from the same base pattern
        if (str1 + str2 != str2 + str1) {
            return "";
        }

        // GCD of the two lengths
        int g = gcd(str1.size(), str2.size());

        // The largest common divisor string
        return str1.substr(0, g);
    }
};
