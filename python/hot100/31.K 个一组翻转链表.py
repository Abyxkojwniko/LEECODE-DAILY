class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        dummy=ListNode(0,head)
        pre,cur=dummy,head
        while(cur):
            check=cur
            for i in range(0,k):
                if check == None:
                    return dummy.next
                check=check.next
            tail=cur
            for i in range(0,k-1):
                temp=cur.next
                tail.next=temp.next
                temp.next=pre.next
                pre.next=temp
            pre=tail
            cur=pre.next
        return dummy.next