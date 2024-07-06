class Solution {
public:
    string intToRoman(int num) {
        map<int, string> map;
        map[1] = "I";
        map[4] = "IV";
        map[5] = "V";
        map[9] = "IX";
        map[10] = "X";
        map[40] = "XL";
        map[50] = "L";
        map[90] = "XC";
        map[100] = "C";
        map[400] = "CD";
        map[500] = "D";
        map[900] = "CM";
        map[1000] = "M";

        string ans;
        // Iterate through map in reverse order of keys
        for (auto it = map.rbegin(); it != map.rend(); ++it) {
            while (num >= it->first) {
                ans += it->second;
                num -= it->first;
            }
        }
        return ans;
    }
};