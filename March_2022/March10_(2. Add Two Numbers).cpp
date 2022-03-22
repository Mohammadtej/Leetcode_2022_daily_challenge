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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum, carry = 0;
        ListNode *res = NULL, *head = NULL;
        
        while(l1 != NULL && l2 != NULL)
        {
            sum = (l1->val + l2->val + carry)%10;
            carry = (l1->val + l2->val + carry)/10;
            
            if(head == NULL)
            {
                head = new ListNode(sum);
                res = head;
            }
            else
            {
                head->next = new ListNode(sum);
                head = head->next;
            }
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1 != NULL)
        {
            sum = (l1->val + carry)%10;
            carry = (l1->val + carry)/10;
            
            if(head == NULL)
            {
                head = new ListNode(sum);
                res = head;
            }
            else
            {
                head->next = new ListNode(sum);
                head = head->next;
            }
            
            l1 = l1->next;
        }
        
        while(l2 != NULL)
        {
            sum = (l2->val + carry)%10;
            carry = (l2->val + carry)/10;
            
            if(head == NULL)
            {
                head = new ListNode(sum);
                res = head;
            }
            else
            {
                head->next = new ListNode(sum);
                head = head->next;
            }
            
            l2 = l2->next;
        }
        
        if(carry > 0)
        {
            if(head == NULL)
            {
                head = new ListNode(carry);
                res = head;
            }
            else
            {
                head->next = new ListNode(carry);
                head = head->next;
            }
        }
        
        return res;
    }
};