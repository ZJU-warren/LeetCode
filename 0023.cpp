/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    #define MY_MAX 0x3f3f3f3f
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode *result = new ListNode();
        ListNode **p = &result->next;

        while(true){
            int minI = -1;
            int minV = MY_MAX; 
            // 这里可以用n堆优化
            for(int i = 0; i < n; ++i){
                if(!lists[i])
                    continue;
                if(lists[i]->val < minV){
                    minV = lists[i]->val;
                    minI = i;
                }
            }
            if(!(~minI))
                break;
            
            *p = lists[minI];
            p = &lists[minI]->next;
            lists[minI] = lists[minI]->next;
        }
        return result->next;
    }
};
