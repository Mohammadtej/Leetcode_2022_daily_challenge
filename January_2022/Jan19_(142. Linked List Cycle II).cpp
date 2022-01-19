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
    ListNode *detectCycle(ListNode *head) {
        map<ListNode *, bool> st;
        
        for(ListNode *i = head; i != NULL; i = i->next)
        {
            if(st.find(i) != st.end())
                return i;
            st[i] = 1;
        }
        
        return NULL;
    }
};