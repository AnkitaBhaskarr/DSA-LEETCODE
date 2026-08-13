class Solution {
public:

    // This function finds the sum of squares of digits
    int getNext(int n) {
        int sum = 0;

        while (n > 0) {
            int digit = n % 10;       // Get last digit
            sum += digit * digit;     // Add square of digit
            n = n / 10;               // Remove last digit
        }

        return sum;
    }

    bool isHappy(int n) {

        // Slow moves one step at a time
        int slow = n;

        // Fast moves two steps at a time
        int fast = getNext(n);

        // Continue until fast reaches 1 or a cycle is detected
        while (fast != 1 && slow != fast) {

            // Slow moves one step
            slow = getNext(slow);

            // Fast moves two steps
            fast = getNext(getNext(fast));
        }

        // If fast reaches 1, n is a happy number
        return fast == 1;
    }
};