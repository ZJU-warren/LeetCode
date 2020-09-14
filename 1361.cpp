class Solution {
    #define Fin(i, f, t) for(int i=f; i<=t; ++i)
    #define MAXN 10200
    #define NIL -1
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int deg[MAXN], father[MAXN];
        memset(deg, 0, sizeof deg);
        memset(father, 0xff, sizeof father);

        Fin(i, 0, n-1){
            if(~leftChild[i]){
                if(~father[leftChild[i]])
                    return false;
                father[leftChild[i]] = i;
                ++deg[i];
            }
                
            if(~rightChild[i]){
                if(~father[rightChild[i]])
                    return false;
                father[rightChild[i]] = i;
                ++deg[i];
            }
        }
        
        int head, num = 0;
        Fin(i, 0, n-1) if(!(~father[i]))
            ++num, head = i;
        if(num != 1)
            return false;
        
        bool visit[MAXN];
        memset(visit, false, sizeof visit);
        DFS(head, visit, leftChild, rightChild);
        Fin(i, 0, n-1) if(!visit[i])
            return false;
        return true;
    }
    bool DFS(int root, bool visit[], vector<int>& leftChild, vector<int>& rightChild){
        if(visit[root])
            return false;
        visit[root] = true;

        bool tag = true;
        if(~leftChild[root])
            tag &= DFS(leftChild[root], visit, leftChild, rightChild);
        
        if(~rightChild[root])
            tag &= DFS(rightChild[root], visit, leftChild, rightChild);
        
        return tag;
    }
};
