class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        pre=None
        p=head
        while p:
            net=p.next
            p.next=pre
            pre=p
            p=net
        return pre