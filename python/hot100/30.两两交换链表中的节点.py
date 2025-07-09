class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy=ListNode(0,head)
        pre=dummy
        while pre.next and pre.next.next:
            temp1=pre.next
            temp2=temp1.next
            lat=temp2.next
            pre.next=temp2
            temp2.next=temp1
            temp1.next=lat
            pre=temp1
        return dummy.next