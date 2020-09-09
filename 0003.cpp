class Solution {
    #define Fin(i,f,t) for(int i=f; i<=t; ++i)
    #define NIL -1
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> exist;
        int maxLen = 0, len = 0, start = 0, n = s.size();
        Fin(i, 0, n-1){
            map<char, int>::iterator it = exist.find(s[i]);
            if(it == exist.end() || it->second == NIL)
               exist[s[i]] = i, ++len;
            else{    
                Fin(j, start, exist[s[i]]-1)
                    exist[s[j]] = NIL, --len;
                start = exist[s[i]] + 1;
                exist[s[i]] = i;
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};
