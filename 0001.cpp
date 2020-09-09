class Solution {
    #define Fin(i,f,t) for(int i=f; i<=t; ++i)
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        int n = nums.size();
        Fin(i,0,n-2){
            Fin(j,i+1,n-1){ 
                if(nums[i] + nums[j] == target){
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }
};
