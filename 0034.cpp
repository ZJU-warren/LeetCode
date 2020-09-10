class Solution {
public:
    int LowerBound(int key, vector<int>& nums){
        int left = 0, right = nums.size();
        while(left < right){
            int mid = (left + right) / 2;
            if(nums[mid] < key)
                left = mid + 1;
            else
                right = mid;
                
        }
        return left;
    }

    int UpperBound(int key, vector<int>& nums){
        int left = 0, right = nums.size();
        while(left < right){
            int mid = (left + right) / 2;
            if(nums[mid] <= key)
                left = mid + 1;
            else
                right = mid;
                
        }
        return right;
    }

    vector<int> Result(int a, int b){
        vector<int> result;
        result.push_back(a);
        result.push_back(b);
        return result;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        
        if(!nums.size())
            return Result(-1, -1);

        int lower = LowerBound(target, nums);
        int upper = UpperBound(target, nums);
        
        if(lower >= nums.size() || nums[lower] != target)
            return Result(-1, -1);
        return Result(lower, upper - 1);
    }
};
