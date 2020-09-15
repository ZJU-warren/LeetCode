class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int p = 0, n = intervals.size();
        while(p < n && intervals[p][1] < newInterval[0])
            result.push_back(intervals[p++]);
        if(p == n){
            result.push_back(newInterval);
            return result;
        }else{
            if(newInterval[1] < intervals[p][0]){
                result.push_back(newInterval);
            }else{
                int start = min(intervals[p][0], newInterval[0]);
                while(p < n && intervals[p][0] <= newInterval[1])
                    ++p;
                int end = max(intervals[p-1][1], newInterval[1]);
                vector<int> temp;
                temp.push_back(start);
                temp.push_back(end);
                result.push_back(temp);
            }
            while(p < n)
                result.push_back(intervals[p++]);
        }
        return result;
    }
};
