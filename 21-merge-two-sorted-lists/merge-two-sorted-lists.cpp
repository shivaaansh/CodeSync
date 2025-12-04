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
        ListNode* prev = new ListNode (-1);
        ListNode* demy = prev;
        while(list1 != NULL && list2 != NULL) {
            if(list1->val > list2->val) {
                prev->next = list2;
                prev = list2;
                list2 = list2->next;
            }
            else {
                prev->next = list1;
                prev = list1;
                list1 = list1->next;
            }
        }
        if(list1 != NULL) {
            prev->next = list1;
        }
        if(list2 != NULL) {
            prev->next = list2;
        }
        return demy->next;
    }
};