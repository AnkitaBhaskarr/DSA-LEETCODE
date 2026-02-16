#include <vector>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        
        for (int a : asteroids) {
            bool destroyed = false;
            
            // Collision only if stack top is positive and current is negative
            while (!st.empty() && st.back() > 0 && a < 0) {
                
                if (abs(st.back()) < abs(a)) {
                    st.pop_back(); // stack asteroid explodes
                }
                else if (abs(st.back()) == abs(a)) {
                    st.pop_back(); // both explode
                    destroyed = true;
                    break;
                }
                else {
                    destroyed = true; // current explodes
                    break;
                }
            }
            
            if (!destroyed) {
                st.push_back(a);
            }
        }
        
        return st;
    }
};
