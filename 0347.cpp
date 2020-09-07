#include <map>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define Fin(i,f,t) for(int i=f;i<=t;++i)
#define Fde(i,f,t) for(int i=f;i>=t;--i)
#define SfI(x) scanf("%d",&x)
#define SfI2(x,y) scanf("%d%d",&x,&y)
#define SfLL(x) scanf("%lld",&x)
#define SfD(x) scanf("%lf",&x)
#define SfC(x) scanf("%c",&x)
#define SfS(x) scanf("%s",x)
typedef long long LL;

//#define DEBUG
#define MAXN 0x3f3f3f3f
#define NIL -1


// get and format input
int GetInput(int nums[], int * k){
    char strNums[1000000];
    scanf("nums = [%[^]]", strNums);
    scanf("], k = %d", k);

    int lenStr = strlen(strNums);
    int p = 0, n = 0;
    while(p < lenStr){
        sscanf(strNums + p, "%d%*c", nums + n++);
        for(++p;strNums[p] == ',' && strNums[p] == ']'; ++p);
        ++p;
    }
    return n;
}

struct MyCmp{
    bool operator()(const pair<int, int> & x, const pair<int, int>  & y) const{
        return x.second > y.second;
    }
};


void Handle(int nums[], int n, int k){
    map<int, int> countMap;
    Fin(i, 0, n-1){
        ++countMap[nums[i]];
    }

    vector<pair<int, int>> vec(countMap.begin(), countMap.end());
    sort(vec.begin(), vec.end(), MyCmp());
    vector<pair<int, int>>::iterator it = vec.begin();

    printf("[%d", it++->first);
    Fin(i, 2, k){
        printf(",%d", it++->first);
    }
    printf("]");
}


int main(void)
{
    freopen("/home/warren/Projects/LeetCode/test.in", "r", stdin);
    //freopen("/home/warren/Projects/LeetCode/test.in", "w", stdout);

    int nums[100000], k;
    int n = GetInput(nums, &k);
    Handle(nums, n, k);

    return 0;
}
