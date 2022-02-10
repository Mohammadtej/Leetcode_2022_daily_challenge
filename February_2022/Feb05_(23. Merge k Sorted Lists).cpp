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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multiset<int> st;
        
        for(ListNode *curr : lists)
        {
            for(; curr != NULL; curr = curr->next)
                st.insert(curr->val);
        }
        
        ListNode *head = NULL, *res = NULL;
        
        for(int x : st)
        {
            // cout << x << " ";
            if(head == NULL)
                head = new ListNode(x), res = head;
            else
            {
                head->next = new ListNode(x);
                head = head->next;
            }
        }
        
        return res;
    }
};