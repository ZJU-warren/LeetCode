class Solution {
public:
    int myAtoi(string str) {
        int p = 0;
        long one = 1;
        while(str[p] == ' ') ++p;
        int sign = 1;
        if(str[p] == '-'){
            sign = -1;
            ++p;
        }
        else if(str[p] == '+'){
            sign = 1;
            ++p;
        }

        long result = 0;
        while('0' <= str[p] && str[p] <= '9'){
            if(result > ((int((one << 31) - 1)) / 10))
                return sign == 1? int((one << 31) - 1) : int(-(one<< 31));
            result = result * 10 + (str[p++] - '0');
            if(result < 0)
                return sign == 1? int((one << 31) - 1) : int(-(one<< 31));
        }
        
        result *= sign;
        if(result < -(one << 31))
            return int(-(one<< 31));
        else if(result > (one << 31) - 1)
            return int((one << 31) - 1);
        return int(result);
    }
};
