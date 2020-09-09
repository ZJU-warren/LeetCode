class Solution {
    #define Fin(i, f, t) for(int i = f; i <= t; ++i)
    #define Fde(i, f, t) for(int i = f; i >= t; --i)
public:
    int maxArea(vector<int>& height) {
        return FindMax(0, height.size()-1, height);
    }
    int FindMax(int left, int right, vector<int>& height){
        if(left >= right)
            return 0;
        int v = min(height[left], height[right]) * (right - left);
        if(height[left] < height[right]){
            Fin(i, left + 1, right - 1) if(height[i] > height[left]){
                v = max(v, FindMax(i, right, height));
                break;
            }
        }else{
            Fde(i, right - 1, left + 1) if(height[i] > height[right]){
                v = max(v, FindMax(left, i, height));
                break;
            }
        }
        return v;
    }

};
