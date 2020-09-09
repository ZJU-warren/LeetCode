class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        char strX[1000];
        sprintf(strX, "%d", x);
        int len = strlen(strX);
        for (int i=0; i<=len/2; ++i){
            if(strX[i] != strX[len-1-i])
                return false;
        }
        return true;
    }
};

