class Solution {
    #define Fin(i, f, t) for(int i = f; i <= t; ++i)
    #define MAXN 1000000
    #define INF 0x3f3f3f3f

    int LowerBound(int key, int n, int dp[]){
        int l = 0, r = n;
        while(l < r){
            int mid = (l + r) / 2;
            if(dp[mid] < key)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }

public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 0;

        int dp[MAXN] = {0, nums[0]}, effect = 1;
        Fin(i, 1, n-1){
            int up = LowerBound(i, effect + 1, dp);
            if(dp[up] < i)
                ++up;
            if(i + nums[i] <= dp[up])   // important, make sure the dp array is non-decreasing
                continue;
            if(effect < up + 1){
                dp[up + 1] = i + nums[i]; 
                ++effect;
            }
            else
                dp[up + 1] = max(dp[up + 1], i + nums[i]);        
        }
        int up = LowerBound(n - 1, effect + 1, dp);
        if(dp[up] < n - 1)
            ++up;
        
        return up;
    }
};
