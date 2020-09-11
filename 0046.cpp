class Solution {
    #define Fin(i, f, t) for(int i=f; i<=t; ++i)
    #define MAXN 1000
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int p[MAXN], n = nums.size();
        bool used[MAXN];
        memset(used, false, sizeof(used));
        vector<vector<int>> result;
        Handle(0, n, p, used, nums, result);
        return result;
    }
    void Handle(int deep, int n, int p[], bool used[], vector<int>& nums, vector<vector<int>>& result){
        if(deep == n){
            vector<int> temp(p, p + n);
            result.push_back(temp);
            return;
        }
        Fin(i, 0, n - 1) if(!used[i]){
            p[deep] = nums[i];
            used[i] = true;
            Handle(deep + 1, n, p, used, nums, result);
            used[i] = false;
        }
    }
};
