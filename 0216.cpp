class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        int p[10];
        Handle(1, n, 0, k, p, result);
        return result;
    }
    void Handle(int deep, int left, int used, int k, int p[], vector<vector<int>>& result){
        if(!left && used == k){
            vector<int> temp(p, p + k);
            result.push_back(temp);
            return;
        }
        if(left < deep || used >= k || deep > 9)
            return;
        
        p[used] = deep;
        Handle(deep + 1, left - deep, used + 1, k, p, result);
        Handle(deep + 1, left, used, k, p, result);
    }
};
