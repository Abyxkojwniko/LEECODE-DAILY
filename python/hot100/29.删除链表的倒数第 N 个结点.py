class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy=ListNode(0,head)
        pre=dummy
        lat=dummy
        for i in range(n):
            lat=lat.next
        while lat.next:
            pre=pre.next
            lat=lat.next
        pre.next=pre.next.next
        return dummy.next