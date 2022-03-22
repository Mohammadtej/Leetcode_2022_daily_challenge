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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = NULL, *tail = NULL;
        
        while(list1 != NULL && list2 != NULL)
        {
            if(list1->val < list2->val)
            {
                if(!head){
                    head = new ListNode(list1->val); 
                    tail = head;
                }
                else
                    tail->next = new ListNode(list1->val), tail = tail->next;
                list1 = list1->next;
            }
            else
            {
                if(!head)
                    head = new ListNode(list2->val), tail = head;
                else
                    tail->next = new ListNode(list2->val), tail = tail->next;
                list2 = list2->next;
            }
        }
        
        while(list1 != NULL)
        {
            if(!head)
                head = new ListNode(list1->val), tail = head;
            else
                tail->next = new ListNode(list1->val), tail = tail->next;
            list1 = list1->next;
        }
        
        while(list2 != NULL)
        {
            if(!head)
                head = new ListNode(list2->val), tail = head;
            else
                tail->next = new ListNode(list2->val), tail = tail->next;
            list2 = list2->next;   
        }
        
        return head;
    }
};