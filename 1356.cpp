class Solution {
    struct Data{
        int value, d;
        Data(int valueT){
            d = 0;
            value = valueT;
            while(valueT){
                if(valueT & 1)
                    ++d;
                valueT >>= 1;
            }
        }
        bool operator<(const Data & A) const{
            if(d != A.d)
                return d < A.d;
            return value < A.value;
        }
    };
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        vector<Data> sortArray;
        for(int i = 0; i < n; ++i)
            sortArray.push_back(Data(arr[i]));
        sort(sortArray.begin(), sortArray.end());
        vector<int> result;
        for(int i = 0; i < n; ++i)
            result.push_back(sortArray[i].value);
        return result;
    }
};
