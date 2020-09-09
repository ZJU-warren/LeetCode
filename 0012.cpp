class Solution {
    #define Fin(i, f, t) for(int i = f; i <= t; ++i)
    #define Fde(i, f, t) for(int i = f; i >= t; --i)
public:
    string intToRoman(int num) {
        char letter[][3] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        int value[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

        string result = "";
        while(num){
            Fde(i, 12, 0) if(num >= value[i]){
                result += letter[i];
                num -= value[i];
                break;
            }
        }
        return result;
    }
};
