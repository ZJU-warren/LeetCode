class ProductOfNumbers {
    vector<int> result;
    vector<int> zeros;

public:
    ProductOfNumbers() {
        result.push_back(1);
        zeros.push_back(0);
    }
    
    void add(int num) {
        if(!num){
            zeros.push_back(result.size());
            result.push_back(1);
        }
        else
            result.push_back(num * result[result.size() - 1]);
    }
    
    int Find(int target){
        int left = 0, right = zeros.size();
        while(left < right){
            int mid = (left + right) / 2;
            if(zeros[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }    
        return left;
    }

    int getProduct(int k) {
        int upper = Find(result.size() - k);
        if(upper == zeros.size())
            return result[result.size() - 1] / result[result.size() - k - 1];
        else
            return 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
