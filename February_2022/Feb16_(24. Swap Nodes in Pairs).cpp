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
    ListNode* swapPairs(ListNode* head) {
        ListNode *curr = head, *next, *prev = NULL;
        
        if(head == NULL)
            return head;
        while(curr != NULL)
        {
            if(curr->next != NULL)
            {
                next = curr->next;
                
                if(prev != NULL)
                {
                    prev->next = next;
                }
                
                curr->next = next->next;
                next->next = curr;
                
                prev = curr;
                
                if(curr == head)
                    head = next;
                curr = curr->next;
            }
            else
            {
                curr = NULL;
            }
            
        }
        
        return head;
    }
};