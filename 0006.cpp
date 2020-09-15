class Solution {
    #define Fin(i, f, t) for(int i = f; i <= t; ++i)
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        int n = s.length();
        string result = "";
        Fin(r, 0, numRows-1){
            int p = r, step = (numRows - r - 1) * 2;
            while(p < n){
                result += s[p];
                if(!step)
                    p +=  (numRows - 1) * 2;
                else if(!r)
                    p += step;
                else{
                    p += step;
                    step = step != r * 2? r * 2 : (numRows - r - 1) * 2;
                }
            }
        }
        return result;
    }
};
