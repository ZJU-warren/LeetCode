class Solution {
    #define INF 0xffffffff
    struct Pair{
        int a, b;
        Pair(int a, int b):a(a), b(b){}
        bool operator<(const Pair & A) const{
            if(a != A.a)
                return a < A.a;
            return b < A.b; 
        }
    };

public:
    int combinationSum4(vector<int>& nums, int target) {
        map<Pair, int> dp;
        int result = Handle(0, target, nums.size(), nums, dp);
        return result;
    }
    int Handle(int deep, int left, int n, vector<int>& nums, map<Pair, int> & dp){
        if(left < 0 || deep == n)
            return 0;
        map<Pair, int>::iterator it = dp.find(Pair(deep, left));
        if(it != dp.end())
            return it->second;
        int result;
        if(!left)
            result = 1;
        else
            result = Handle(0, left - nums[deep], n, nums, dp) + Handle(deep + 1, left, n, nums, dp);
        dp[Pair(deep, left)] = result;
        return result;
    }
};
