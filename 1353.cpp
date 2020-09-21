class Solution {
public:
    static bool Cmp(const vector<int> & a, const vector<int> & b){
        if(a[1] != b[1])
            return a[1] < b[1];
        return a[0] < b[0];
    }
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), Cmp);
        int result = 0, d = 1, n = events.size();
        for(int i = 0; i < n; ++i) if(d <= events[i][1]){
            result += 1;
            d = max(d, events[i][0]) + 1;
        }
        return result;
    }
};
