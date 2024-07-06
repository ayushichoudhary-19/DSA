class Solution {
public:
    int strStr(string haystack, string needle) {
        int h = haystack.size();
        int n = needle.size();
        
        // If needle is empty, return 0
        if (n == 0) return 0;
        
        // If needle is longer than haystack, it can't be found
        if (n > h) return -1;
        
        for (int i = 0; i <= h - n; ++i) {
            if (haystack.substr(i, n) == needle) {
                return i;
            }
        }
        
        return -1;
    }
};
