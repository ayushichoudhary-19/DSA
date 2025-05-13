class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int mod = 1e9 + 7;

        vector<int> m(26);

        for (char ch : s) {
            m[ch - 'a']++;
        }

        for (int round = 0; round < t; round++) {
            vector<int> temp(26, 0);

            for (int i = 0; i < 26; i++) {
                if (i < 25) {
                    temp[i + 1] = (temp[i + 1] + m[i]) % mod;

                } else {
                    temp[0] = (temp[0] + m[i]) % mod;
                    temp[1] = (temp[1] + m[i]) % mod;
                }
            }

            m = move(temp);
        }

        int result = 0;
        for (int i = 0; i < 26; i++) {
            result = (result + m[i]) % mod;
        }

        return result;
    }
};
