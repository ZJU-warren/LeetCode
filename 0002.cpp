/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = new ListNode(0); 
        ListNode *p = result, *pre;
        while(l1 && l2){
            p->val += l1->val + l2->val;
            p->next = new ListNode(p->val / 10);
            p->val %= 10;
            
            pre = p;
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode *end = l1 != NULL? l1: l2;

        while(end){
            p->val += end->val;
            p->next = new ListNode(p->val / 10);
            p->val %= 10;

            pre = p;
            p = p->next;
            end = end->next;
        }

        if(!p->val)
            pre->next = NULL;
        
        return result;
        
    }
};

