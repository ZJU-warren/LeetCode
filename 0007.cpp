class Solution {
public:
    int reverse(int x) {
        int sign = x > 0? 1 : -1;
        long result = 0;
        long tx = (long) x * sign;
        while(tx){
            result = result * 10 + (tx % 10);
            tx /= 10;
        }    
        if(sign * result < -((long) 1 << 31) || sign * result > ((long) 1 << 31) - 1)
            return 0;
        return (int)(sign * result); 
    }
};
