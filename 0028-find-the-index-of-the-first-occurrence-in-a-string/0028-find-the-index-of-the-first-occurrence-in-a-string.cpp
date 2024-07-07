class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        
        if (m == 0) return 0; // Edge case: needle is empty, return 0
        
        // Compute the hash values and the RADIX
        long long RADIX = 26;
        long long MOD = 1e9 + 7;
        long long hashNeedle = 0;
        long long hashHay = 0;
        long long MAX_WEIGHT = 1;

        // Calculate RADIX^m % MOD and hash value of needle
        for (int i = 0; i < m; ++i) {
            hashNeedle = (hashNeedle * RADIX + (needle[i] - 'a')) % MOD;
            hashHay = (hashHay * RADIX + (haystack[i] - 'a')) % MOD;
            MAX_WEIGHT = (MAX_WEIGHT * RADIX) % MOD;
        }

        // Sliding window to check each substring of haystack
        for (int i = 0; i <= n - m; ++i) {
            if (hashNeedle == hashHay) {
                // Check character by character if the substrings match
                int j;
                for (j = 0; j < m; ++j) {
                    if (needle[j] != haystack[i + j]) {
                        break;
                    }
                }
                if (j == m) return i; // Found the substring at index i
            }
            
            // Update hashHay for the next substring in haystack
            if (i < n - m) {
                hashHay = ((hashHay * RADIX - (haystack[i] - 'a') * MAX_WEIGHT % MOD + (haystack[i + m] - 'a')) % MOD + MOD) % MOD;
            }
        }
        
        return -1; // Substring not found
    }
};
