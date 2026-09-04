class Solution {
public:
    bool isPalindrome(int x) {
        if (x >= 0) {

            int num = x;
            int rev = 0;
            while (num != 0) {
                int digit = num % 10;
                rev = rev * 10 + digit;
                num = num / 10;
            }
            return rev == x;

        } else {
            return false;
        }
    }
};