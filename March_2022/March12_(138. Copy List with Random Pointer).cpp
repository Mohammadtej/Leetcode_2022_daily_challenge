/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *l = NULL, *res = NULL;
        map<Node*, Node*> mp;
        
        int j = 0;
        
        mp[NULL] = NULL;
        for(Node *i = head; i != NULL; i = i->next)
        {
            if(l == NULL)
            {
                l = new Node(i->val);
                mp[i] = l;
                res = l;
            }
            else
            {
                l->next = new Node(i->val);
                l = l->next;
                mp[i] = l;
            }
        }
        
        l = res;
        
        for(Node *i = head; i != NULL; i = i->next, l = l->next)
        {
            l->random = mp[i->random];
        }
        
        return res;
    }
};