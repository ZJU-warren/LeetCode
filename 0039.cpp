class Solution {
    #define Fin(i, f, t) for(int i = f; i <=t ; ++i)
    #define MAXN 35
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        int p[MAXN], n = candidates.size();
        Search(p, 0, 0, n, target, results, candidates);
        return results;
    }
    void Search(int p[], int deep, int start, int end, int target, vector<vector<int>>& results, vector<int>& candidates){
        if(target == 0){
            vector<int> result;
            Fin(i, 0, deep-1)
                result.push_back(p[i]);
            results.push_back(result);
            return;
        }

        if(target < 0 || start >= end)
            return;

        Fin(i, start, end-1){
            p[deep] = candidates[i];
            Search(p, deep+1, i, end, target - candidates[i], results, candidates);
        }
    }
};
