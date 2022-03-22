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
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* l2 = NULL, *last_node = NULL, *l1 = NULL;
        
        if(head == NULL)
            return head;
        
        int sz_ll = 0;
        for(ListNode *i = head; i != NULL; i = i->next)
        {
            sz_ll++;
            
            if(i != NULL)
                last_node = i;
        }
        
        k %= sz_ll;
        
        if(k == 0)
            return head;
        
        k = sz_ll - k;
        for(ListNode *i = head; i != NULL && k > 0; i = i->next, k--)
        {
            l1 = i;
            l2 = i->next;
        }
        
        l1->next = NULL;
        last_node->next = head;
        head = l2;
        
        return head;
    }
};