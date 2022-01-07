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
    int num[10000];
    int n;
    Solution(ListNode* head) {
        int i = 0;        
        for(ListNode* tp = head; tp != NULL; tp = tp->next)
            num[i++] = (tp->val);
        n = i;
    }
    
    int getRandom() {
        int v = num[rand()%n];
        return v;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */