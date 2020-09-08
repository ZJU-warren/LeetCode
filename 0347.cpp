class Solution {
    #define Fin(i,f,t) for(int i=f;i<=t;++i)
public:
    struct MyCmp{
        bool operator()(const pair<int, int> & x, const pair<int, int>  & y) const{
            return x.second > y.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> countMap;
        Fin(i, 0, n-1){
            ++countMap[nums[i]];
        }

        vector<pair<int, int>> vec(countMap.begin(), countMap.end());
        sort(vec.begin(), vec.end(), MyCmp());
        vector<pair<int, int>>::iterator it = vec.begin();

        vector<int> result;
        Fin(i, 1, k)
            result.push_back(it++->first);
        return result;
    }
};
