class Solution {
public:
     int myAtoi(std::string s) {
        int i = 0;
        int n = s.size();
        int sign = 1;
        int result = 0;

        // Skip leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Check sign
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Convert digits to integer
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Check for overflow and underflow
            if (result > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return result * sign;
    }
};