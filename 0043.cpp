class Solution {
    #define Fin(i, f, t) for(int i = f; i <= t; ++i)
    #define MAXN 300

public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int len1 = num1.size(), len2 = num2.size();
        const char* a = num1.data();
        const char* b = num2.data();

        int result[MAXN];
        memset(result, 0, sizeof(result));
        Fin(i, 0, len1 - 1){
            Fin(j, 0, len2 - 1)
                result[i + j] += (a[i] - '0') * (b[j] - '0');
            Fin(j, 0, i + len2) if(result[j] >= 10){
                result[j + 1] += result[j] / 10;
                result[j] %= 10;
            }
        }

        int lenRes = MAXN;
        while(!result[lenRes - 1])
            --lenRes;

        char str[MAXN];
        memset(str, '\0', sizeof(str));
        Fin(i, 0, lenRes - 1)
            str[i] = result[lenRes - i - 1] + '0';
        return str;
    }
};
