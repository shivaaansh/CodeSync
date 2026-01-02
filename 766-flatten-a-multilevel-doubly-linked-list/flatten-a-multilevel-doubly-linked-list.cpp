/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL) return head;
        Node* dum = new Node(0);
        dum->next = head;
        fun(dum, head);
        dum->next->prev = NULL;
        return dum->next;
    }
    Node* fun(Node* intersection, Node* head) {
        if(head == NULL) {
            return intersection;
        }
        head->prev = intersection;
        intersection->next = head;
        Node* next = head->next;
        if(head->child) {           
            Node* tail = fun(head, head->child);
            head->child = NULL;
            return fun(tail, next);
        }
        return fun(head, next);
    }
};