/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode tailA = headA;
        ListNode tailB = headB;
        ListNode head1 = headA;
        ListNode head2 = headB;
        int count1 =0;
        int count2 =0;
        if(headA == null || headB == null ){
            return null;
        }
        while(head1 != head2){
            if(head1==null){
                head1=headB;
            }else{
                head1=head1.next;
                
            }if(head2==null){
                head2=headA;
                
            }else{
                head2=head2.next;
            }
            
        }return head1;
    }
}