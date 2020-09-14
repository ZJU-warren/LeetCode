class Solution {
    #define MAXN 120
    #define Fin(i, f, t) for(int i=f; i<=t; ++i)
public:
    void DFS(int root, vector<vector<int>>& edges, int num[], int farther[], int visit[], int & numVisit){
        Fin(vi, 0, numVisit-1){
            int i = visit[vi];    
            if(edges[i][0] == root && edges[i][1] != farther[edges[i][0]]){
                ++num[root];
                farther[edges[i][1]] = root;
                swap(visit[vi], visit[--numVisit]);
                DFS(edges[i][1], edges, num, farther, visit, numVisit);
                DFS(root, edges, num, farther, visit, numVisit);
                break;
            }
            else if(edges[i][1] == root && edges[i][0] != farther[edges[i][1]]){
                ++num[root];
                farther[edges[i][0]] = root;
                swap(visit[vi], visit[--numVisit]);
                DFS(edges[i][0], edges, num, farther, visit, numVisit);
                DFS(root, edges, num, farther, visit, numVisit);
                break;
            }
        }
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        int farther[MAXN], num[MAXN], m=edges.size();
        int visit[MAXN], numVisit=m;
        Fin(i, 0, m-1)
            visit[i] = i;
        memset(num, 0, sizeof(num));
        memset(farther, 0, sizeof(farther));
        DFS(1, edges, num, farther, visit, numVisit);
        return Cal(target, t, farther, num, num[target] == 0);
    }
    double Cal(int target, int t, int farther[], int num[], bool tag){
        if(target == 1)
            return (t == 0 || tag)? 1.0 : 0;
        if(t == 0)
            return 0.0;
        return Cal(farther[target], t - 1, farther, num, tag) / num[farther[target]];
    }
};
